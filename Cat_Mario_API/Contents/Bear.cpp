#include "PreCompile.h"
#include "Bear.h"

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


Bear::Bear()
{
	{
		MonsterRenderer = CreateDefaultSubObject<USpriteRenderer>();
		MonsterRenderer->SetSprite("Bear_Left.png");
		MonsterRenderer->SetOrder(ERenderOrder::PLAYER);
		MonsterRenderer->SetComponentScale({ 68, 114 });
	}
	{
		MonsterBody = CreateDefaultSubObject<U2DCollision>();
		MonsterBody->SetComponentScale({ 68, 114 });
		MonsterBody->SetCollisionGroup(ECollisionGroup::MonsterBody);
		MonsterBody->SetCollisionType(ECollisionType::Rect);
	}

	DebugOn();
}

Bear::~Bear()
{
}

void Bear::BeginPlay()
{
	Super::BeginPlay();
}

void Bear::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	JumpUp(_DeltaTime);

	Timer += _DeltaTime;

	if (Timer >= 0.1f)
	{
		Move(_DeltaTime);
	}
}

void Bear::Move(float _DeltaTime)
{
	MonsterGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);

	FVector2D MonsterPos = this->GetActorLocation();

	TurnAround(MoveDir);
	AddActorLocation(MoveDir * 0.08f);
}

void Bear::MonsterGroundCheck(FVector2D _MovePos)
{
	IsGround = false;

	if (nullptr != ColImage)
	{
		// 픽셀충돌에서 제일 중요한건 애초에 박히지 않는것이다.
		FVector2D MonsterScale = MonsterRenderer->GetTransform().Scale;
		FVector2D NextPos = GetActorLocation() + FVector2D{ 0, 57 } + _MovePos;

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

void Bear::Gravity(float _DeltaTime)
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


void Bear::TurnAround(FVector2D _MovePos)
{
	FVector2D MonsterPos = this->GetActorLocation();

	if (nullptr != ColImage)
	{
		// 미래의 몬스터 위치
		FVector2D NextPos = MonsterPos + FVector2D{ 34.0f * PosOrN, 0.0 } + _MovePos;

		NextPos.X = floorf(NextPos.X);
		NextPos.Y = floorf(NextPos.Y);

		UColor Color = ColImage->GetColor(NextPos, UColor::WHITE);
		if (Color == UColor::BLACK)
		{
			//왼쪽으로 가다가 픽셀 충돌할 시 오른쪽으로 방향 변경
			if (MoveDir == FVector2D::LEFT)
			{
				MonsterRenderer->SetSprite("Bear_Right.png");
				MoveDir = FVector2D::RIGHT;
				PosOrN = 1.0f;
			}
			//오른쪽으로 가다가 픽셀 충돌할 시 왼쪽으로 방향 변경
			else
			{
			
				MonsterRenderer->SetSprite("Bear_Left.png");
				MoveDir = FVector2D::LEFT;
				PosOrN = -1.0f;
			}

		}
	}
}

void Bear::JumpUp(float _DeltaTime)
{
	if (IsGround == false && DoItOnce == true)
	{
		AddActorLocation(JumpPower * _DeltaTime);
	}
	else if (IsGround == true)
	{
		DoItOnce = false;
	}
}
