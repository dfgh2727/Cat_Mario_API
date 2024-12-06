#include "PreCompile.h"
#include "KingWC.h"

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
#include "BigWC.h"


KingWC::KingWC()
{
	{
		MonsterRenderer = CreateDefaultSubObject<USpriteRenderer>();
		MonsterRenderer->SetSprite("KingWC_Left.png");
		MonsterRenderer->SetOrder(ERenderOrder::PLAYER);
		MonsterRenderer->SetComponentScale({ 64, 66 });
	}
	{
		MonsterBody = CreateDefaultSubObject<U2DCollision>();
		MonsterBody->SetComponentScale({ 64, 66 });
		MonsterBody->SetCollisionGroup(ECollisionGroup::MonsterBody);
		MonsterBody->SetCollisionType(ECollisionType::Rect);
	}

	DebugOn();
}

KingWC::~KingWC()
{
}

void KingWC::BeginPlay()
{
	Super::BeginPlay();
}

void KingWC::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (Jump == true)
	{
		JumpUp(_DeltaTime);
	}
	Move(_DeltaTime);
	Grow();
}

void KingWC::Move(float _DeltaTime)
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

void KingWC::MonsterGroundCheck(FVector2D _MovePos)
{
	IsGround = false;

	if (nullptr != ColImage)
	{
		// 픽셀충돌에서 제일 중요한건 애초에 박히지 않는것이다.
		FVector2D MonsterScale = MonsterRenderer->GetTransform().Scale;
		FVector2D NextPos = GetActorLocation() + FVector2D{ 0, 33 } + _MovePos;

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

void KingWC::Gravity(float _DeltaTime)
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

bool KingWC::OnTheBlock(float _DeltaTime)
{
	std::vector<AActor*> SteppingBlock;
	bool IsOnTheBlock = MonsterBody
		->Collision(static_cast<int>(ECollisionGroup::SquareBlock), SteppingBlock, GravityForce * _DeltaTime, 100);
	return IsOnTheBlock;
}

void KingWC::TurnAround(FVector2D _MovePos)
{
	FVector2D MonsterPos = this->GetActorLocation();

	if (nullptr != ColImage)
	{
		// 미래의 몬스터 위치
		FVector2D NextPos = MonsterPos + FVector2D{ 32.0f * PosOrN, 0.0 } + _MovePos;

		NextPos.X = floorf(NextPos.X);
		NextPos.Y = floorf(NextPos.Y);

		UColor Color = ColImage->GetColor(NextPos, UColor::WHITE);
		if (Color == UColor::BLACK)
		{
			//왼쪽으로 가다가 픽셀 충돌할 시 오른쪽으로 방향 변경
			if (MoveDir == FVector2D::LEFT)
			{
				MonsterRenderer->SetSprite("KingWC_Right.png");
				MoveDir = FVector2D::RIGHT;
				PosOrN = 1.0f;
			}
			//오른쪽으로 가다가 픽셀 충돌할 시 왼쪽으로 방향 변경
			else
			{
				MonsterRenderer->SetSprite("KingWC_Left.png");
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
			MonsterRenderer->SetSprite("KingWC_Right.png");
			MoveDir = FVector2D::RIGHT;
			PosOrN = 1.0f;
		}
		//오른쪽으로 가다가 픽셀 충돌할 시 왼쪽으로 방향 변경
		else
		{
			MonsterRenderer->SetSprite("KingWC_Left.png");
			MoveDir = FVector2D::LEFT;
			PosOrN = -1.0f;
		}
	}

	//몬스터가 맵의 왼쪽 끝에 닿을 경우 방향 변경
	if (MonsterPos.X <= 0.0)
	{
		MonsterRenderer->SetSprite("KingWC_Right.png");
		MoveDir = FVector2D::RIGHT;
		PosOrN = 1.0f;
	}
}

void KingWC::JumpUp(float _DeltaTime)
{
	if (IsGround == false && DoItOnce == true)
	{
		AddActorLocation(JumpPower * _DeltaTime);
	}
	else if(IsGround == true)
	{
		DoItOnce = false;
	}
}

void KingWC::Grow()
{
	AActor* Result = MonsterBody->CollisionOnce(ECollisionGroup::GettingBig);
	if (nullptr != Result)
	{
		FVector2D PresentPos = this->GetActorLocation();
		UEngineWinImage* ColImageForBigWC = this->GetColImage();

		BigWC* BigWhiteCircle = GetWorld()->SpawnActor<BigWC>();
		BigWhiteCircle->SetActorLocation(PresentPos);
		BigWhiteCircle->ColImage = ColImageForBigWC;

		Result->Destroy();
		this->Destroy();
	}
}