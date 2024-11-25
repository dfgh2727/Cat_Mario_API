#include "PreCompile.h"
#include "TurtleShell.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>
#include <EngineBase/EngineMath.h>
#include <EngineCore/ImageManager.h>
#include <EnginePlatform/EngineInput.h>

#include "Enum.h"

TurtleShell::TurtleShell()
{
	{
		MonsterRenderer = CreateDefaultSubObject<USpriteRenderer>();
		MonsterRenderer->SetSprite("CMshell_Right.png");
		MonsterRenderer->SetOrder(ERenderOrder::PLAYER);
		MonsterRenderer->SetComponentScale({ 60, 54 });
	}
	{
		MonsterBody = CreateDefaultSubObject<U2DCollision>();
		MonsterBody->SetComponentScale({ 60, 54 });
		MonsterBody->SetCollisionGroup(ECollisionGroup::MonsterBody);
		MonsterBody->SetCollisionType(ECollisionType::Rect);
	}
	{
		BouncyBody = CreateDefaultSubObject<U2DCollision>();
		BouncyBody->SetComponentScale({ 60, 54 });
		BouncyBody->SetCollisionGroup(ECollisionGroup::BouncyObject);
		BouncyBody->SetCollisionType(ECollisionType::Rect);
	}

	DebugOn();
}

TurtleShell::~TurtleShell()
{
}

void TurtleShell::BeginPlay()
{
	Super::BeginPlay();
}

void TurtleShell::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
} 

void TurtleShell::Move(float _DeltaTime)
{

}

void TurtleShell::MonsterGroundCheck(FVector2D _MovePos)
{
	IsGround = false;

	if (nullptr != ColImage)
	{
		// 픽셀충돌에서 제일 중요한건 애초에 박히지 않는것이다.
		FVector2D MonsterScale = MonsterRenderer->GetTransform().Scale;
		FVector2D NextPos = GetActorLocation() + _MovePos;

		NextPos.X = floorf(NextPos.X);
		NextPos.Y = floorf(NextPos.Y);

		UColor Color = ColImage->GetColor(NextPos, UColor::WHITE);
		if (Color == UColor::WHITE)
		{
			IsGround = false;
		}
		else if (Color == UColor::BLACK)
		{
			IsGround = true;
		}
	}

	while (true)
	{
		UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
		if (Color == UColor::BLACK)
		{
			AddActorLocation(FVector2D::UP);
		}
		else
		{
			break;
		}
	}
}

void TurtleShell::Gravity(float _DeltaTime)
{
	if (false == IsGround)
	{
		AddActorLocation(GravityForce * _DeltaTime);
		GravityForce += FVector2D::DOWN * _DeltaTime * 1200.0f;
	}
	else
	{
		GravityForce = FVector2D::ZERO;
	}

}

bool TurtleShell::OnTheBlock(float _DeltaTime)
{
	std::vector<AActor*> SteppingBlock;
	bool IsOnTheBlock = MonsterBody
		->Collision(static_cast<int>(ECollisionGroup::SquareBlock), SteppingBlock, GravityForce * _DeltaTime, 100);
	return IsOnTheBlock;
}

void TurtleShell::TurnAround(FVector2D _MovePos)
{
	FVector2D MonsterPos = this->GetActorLocation();

	if (nullptr != ColImage)
	{
		// 미래의 몬스터 위치
		FVector2D NextPos = MonsterPos + FVector2D{ 27.0f * PosOrN, 0.0 } + _MovePos;

		NextPos.X = floorf(NextPos.X);
		NextPos.Y = floorf(NextPos.Y);

		UColor Color = ColImage->GetColor(NextPos, UColor::WHITE);
		if (Color == UColor::BLACK)
		{
			//왼쪽으로 가다가 픽셀 충돌할 시 오른쪽으로 방향 변경
			if (MoveDir == FVector2D::LEFT)
			{
				MonsterRenderer->SetSprite("CMshell_Right.png");
				MoveDir = FVector2D::RIGHT;
				PosOrN = 1.0f;
			}
			//오른쪽으로 가다가 픽셀 충돌할 시 왼쪽으로 방향 변경
			else
			{
				MonsterRenderer->ChangeAnimation("CMshell_Left.png");
				MoveDir = FVector2D::LEFT;
				PosOrN = -1.0f;
			}

		}

	}

	AActor* Result = MonsterBody->CollisionOnce(ECollisionGroup::SquareBlock);
	if (nullptr != Result)
	{
		if (MoveDir == FVector2D::LEFT)
		{
			MonsterRenderer->ChangeAnimation("CMshell_Right.png");
			MoveDir = FVector2D::RIGHT;
			PosOrN = 1.0f;
		}
		//오른쪽으로 가다가 픽셀 충돌할 시 왼쪽으로 방향 변경
		else
		{
			MonsterRenderer->ChangeAnimation("CMshell_Left.png");
			MoveDir = FVector2D::LEFT;
			PosOrN = -1.0f;
		}
	}

	//몬스터가 맵의 왼쪽 끝에 닿을 경우 방향 변경
	if (MonsterPos.X <= 0.0)
	{
		MonsterRenderer->ChangeAnimation("CMshell_Right.png");
		MoveDir = FVector2D::RIGHT;
		PosOrN = 1.0f;
	}
}