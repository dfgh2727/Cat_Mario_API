#include "PreCompile.h"
#include "WhiteCircle.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>
#include <EngineBase/EngineMath.h>
#include <EngineCore/ImageManager.h>
#include <EnginePlatform/EngineInput.h>

#include "MapActor.h"

#include "GameMode_FirstMap.h"
#include "Enum.h"
#include "MarioCat.h"


WhiteCircle::WhiteCircle()
{
	{
		MonsterRenderer = CreateDefaultSubObject<USpriteRenderer>();
		MonsterRenderer->SetSprite("CMmon_Right.png");
		MonsterRenderer->SetOrder(ERenderOrder::PLAYER);
		MonsterRenderer->SetComponentScale({ 120, 120 });
	}
	{
		MonsterBody = CreateDefaultSubObject<U2DCollision>();
		MonsterBody->SetComponentScale({ 55, 53 });
		MonsterBody->SetCollisionGroup(ECollisionGroup::MonsterBody);
		MonsterBody->SetCollisionType(ECollisionType::Rect);
	}
	{
		BouncyBody = CreateDefaultSubObject<U2DCollision>();
		BouncyBody->SetComponentScale({ 55, 53 });
		BouncyBody->SetCollisionGroup(ECollisionGroup::BouncyObject);
		BouncyBody->SetCollisionType(ECollisionType::Rect);
	}

	MonsterRenderer->CreateAnimation("Mon_RunRight", "CMmon_Right.png", 0, 0, 0.5f);
	MonsterRenderer->CreateAnimation("Mon_RunLeft", "CMmon_Left.png", 0, 0, 0.5f);

	MonsterRenderer->ChangeAnimation("Mon_RunLeft");

	DebugOn();
}

WhiteCircle::~WhiteCircle()
{
}

void WhiteCircle::BeginPlay()
{
	Super::BeginPlay();
}

void WhiteCircle::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Move(_DeltaTime);
	IsKilled(_DeltaTime);

	GetOutOfBox(_DeltaTime);
	RiseUp(_DeltaTime);
}

void WhiteCircle::Move(float _DeltaTime)
{
	MonsterGroundCheck(GravityForce * _DeltaTime);
	if (true == OnTheBlock(_DeltaTime))
	{
		IsGround = true;
	}
	Gravity(_DeltaTime);

	FVector2D MonsterPos = this->GetActorLocation();

	TurnAround(MoveDir);
	AddActorLocation(MoveDir * 0.08f);
}

void WhiteCircle::MonsterGroundCheck(FVector2D _MovePos)
{
	IsGround = false;

	if (nullptr != ColImage)
	{
		// 픽셀충돌에서 제일 중요한건 애초에 박히지 않는것이다.
		FVector2D MonsterScale = MonsterRenderer->GetTransform().Scale;
		FVector2D NextPos = GetActorLocation()+ FVector2D{ 0, 22 } + _MovePos;

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

void WhiteCircle::Gravity(float _DeltaTime)
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

bool WhiteCircle::OnTheBlock(float _DeltaTime)
{
	std::vector<AActor*> SteppingBlock;
	bool IsOnTheBlock = MonsterBody
		->Collision(static_cast<int>(ECollisionGroup::SquareBlock), SteppingBlock, GravityForce * _DeltaTime, 100);
	return IsOnTheBlock;
}

void WhiteCircle::IsKilled(float _DeltaTime)
{
	MarioCat* MainPlayer = GetWorld()->GetPawn<MarioCat>();
	AActor* Result = MonsterBody->CollisionOnce(ECollisionGroup::PlayerFoot);
	if (nullptr != Result)
	{
		if ((MainPlayer->GetPlayerState() == PlayerState::Jump) && (MainPlayer->IsCatKilled == false))
		{
			this->Destroy();
		}
	}
}

void WhiteCircle::TurnAround(FVector2D _MovePos)
{
	FVector2D MonsterPos = this->GetActorLocation();

	if (nullptr != ColImage)
	{
		// 미래의 몬스터 위치
		FVector2D NextPos = MonsterPos + FVector2D{ 28.0f * PosOrN, 0.0 } + _MovePos;

		NextPos.X = floorf(NextPos.X);
		NextPos.Y = floorf(NextPos.Y);

		UColor Color = ColImage->GetColor(NextPos, UColor::WHITE);
		if (Color == UColor::BLACK)
		{
			//왼쪽으로 가다가 픽셀 충돌할 시 오른쪽으로 방향 변경
			if (MoveDir == FVector2D::LEFT)
			{
				MonsterRenderer->ChangeAnimation("Mon_RunRight");
				MoveDir = FVector2D::RIGHT;
				PosOrN = 1.0f;
			}
			//오른쪽으로 가다가 픽셀 충돌할 시 왼쪽으로 방향 변경
			else
			{
				MonsterRenderer->ChangeAnimation("Mon_RunLeft");
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
			MonsterRenderer->ChangeAnimation("Mon_RunRight");
			MoveDir = FVector2D::RIGHT;
			PosOrN = 1.0f;
		}
		//오른쪽으로 가다가 픽셀 충돌할 시 왼쪽으로 방향 변경
		else
		{
			MonsterRenderer->ChangeAnimation("Mon_RunLeft");
			MoveDir = FVector2D::LEFT;
			PosOrN = -1.0f;
		}
	}

	//몬스터가 맵의 왼쪽 끝에 닿을 경우 방향 변경
	if (MonsterPos.X <= 0.0)
	{
		MonsterRenderer->ChangeAnimation("Mon_RunRight");
		MoveDir = FVector2D::RIGHT;
		PosOrN = 1.0f;
	}
}

bool WhiteCircle::GetOutOfBox(float _DeltaTime)
{
	std::vector<AActor*> InsideOfBox;
	bool InTheBox = MonsterBody
		->Collision(static_cast<int>(ECollisionGroup::MysteryBox), InsideOfBox, FVector2D::DOWN, 100);
	return InTheBox;
}


void WhiteCircle::RiseUp(float _DeltaTime)
{
	if (true == GetOutOfBox(_DeltaTime))
	{
		MonsterRenderer->ChangeAnimation("Mon_RunRight");
		AddActorLocation(FVector2D::UP * 0.25f);
	}
}
