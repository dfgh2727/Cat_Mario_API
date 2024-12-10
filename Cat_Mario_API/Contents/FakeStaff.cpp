#include "PreCompile.h"
#include "FakeStaff.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "Enum.h"
#include "MarioCat.h"

FakeStaff::FakeStaff()
{
	StaffRenderer = CreateDefaultSubObject<USpriteRenderer>();
	StaffRenderer->SetSprite("FakeStaff.png");
	StaffRenderer->SetOrder(ERenderOrder::PROP);
	StaffRenderer->SetComponentScale({ 44, 620 });

	{
		CollisionComponent1 = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent1->SetComponentScale({ 44, 42 });
		CollisionComponent1->SetCollisionGroup(ECollisionGroup::BouncyObject);
		CollisionComponent1->SetCollisionType(ECollisionType::Rect);
		CollisionComponent1->SetComponentLocation(FVector2D{ 0, -289 });

	}
	{
		CollisionComponent2 = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent2->SetComponentScale({ 20, 576 });
		CollisionComponent2->SetCollisionGroup(ECollisionGroup::Prop);
		CollisionComponent2->SetCollisionType(ECollisionType::Rect);
		CollisionComponent2->SetComponentLocation(FVector2D{ 0, 20 });
	}

	DebugOn();
}

FakeStaff::~FakeStaff()
{
}

void FakeStaff::BeginPlay()
{
	Super::BeginPlay();
}

void FakeStaff::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (MoveSwitch == true)
	{
		SetDirection();
		Move(_DeltaTime);
	}
}

void FakeStaff::Move(float _DeltaTime)
{
	MonsterGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);

	TurnAround(MoveDir);
	AddActorLocation(MoveDir * 0.1f);

}

void FakeStaff::MonsterGroundCheck(FVector2D _MovePos)
{
	IsGround = false;

	if (nullptr != ColImage)
	{
		// 픽셀충돌에서 제일 중요한건 애초에 박히지 않는것이다.
		FVector2D MonsterScale = StaffRenderer->GetTransform().Scale;
		FVector2D NextPos = GetActorLocation() + FVector2D{ 0, 310 } + _MovePos;

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

void FakeStaff::Gravity(float _DeltaTime)
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


void FakeStaff::TurnAround(FVector2D _MovePos)
{
	FVector2D MonsterPos = this->GetActorLocation();

	if (nullptr != ColImage)
	{
		// 미래의 몬스터 위치
		FVector2D NextPos = MonsterPos + FVector2D{ 10.0f * PosOrN, 310.0 } + _MovePos;

		NextPos.X = floorf(NextPos.X);
		NextPos.Y = floorf(NextPos.Y);

		UColor Color = ColImage->GetColor(NextPos, UColor::WHITE);
		if (Color == UColor::BLACK)
		{
			//왼쪽으로 가다가 픽셀 충돌할 시 오른쪽으로 방향 변경
			if (MoveDir == FVector2D::LEFT)
			{
				MoveDir = FVector2D::RIGHT;
				PosOrN = 1.0f;
			}
			//오른쪽으로 가다가 픽셀 충돌할 시 왼쪽으로 방향 변경
			else
			{
				MoveDir = FVector2D::LEFT;
				PosOrN = -1.0f;
			}

		}

	}

	AActor* Result = CollisionComponent2->CollisionOnce(ECollisionGroup::SquareBlock);
	if (nullptr != Result)
	{
		if (MoveDir == FVector2D::LEFT)
		{
			MoveDir = FVector2D::RIGHT;
			PosOrN = 1.0f;
		}
		else
		{
			MoveDir = FVector2D::LEFT;
			PosOrN = -1.0f;
		}
	}
}

void FakeStaff::SetDirection()
{
	if(GoRight == true)
	{
		MoveDir = FVector2D::RIGHT;
		PosOrN = 1.0f;
		GoRight = false;
	}

	if (GoLeft == true)
	{
		MoveDir = FVector2D::LEFT;
		PosOrN = -1.0f;
		GoLeft = false;
	}
}
