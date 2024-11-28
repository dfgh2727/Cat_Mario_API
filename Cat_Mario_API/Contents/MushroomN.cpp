#include "PreCompile.h"
#include "MushroomN.h"

#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include <EngineCore/EngineAPICore.h>

MushroomN::MushroomN()
{
	MushroomRenderer = CreateDefaultSubObject<USpriteRenderer>();
	MushroomRenderer->SetSprite("MushroomN.png");
	MushroomRenderer->SetOrder(ERenderOrder::PROP);
	MushroomRenderer->SetComponentScale({ 46, 48 });
	
	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 46, 48 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::None);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	DebugOn();
}

MushroomN::~MushroomN()
{
}

void MushroomN::BeginPlay()
{
	Super::BeginPlay();
}

void MushroomN::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Move(_DeltaTime);
	GetOutOfBox(_DeltaTime);
	RiseUp(_DeltaTime);
	Eaten();
}

void MushroomN::Move(float _DeltaTime)
{
	MushroomGroundCheck(GravityForce * _DeltaTime);
	if (true == OnTheBlock(_DeltaTime))
	{
		IsGround = true;
	}
	Gravity(_DeltaTime);

	FVector2D MushroomPos = this->GetActorLocation();

	TurnAround(MoveDir);
	AddActorLocation(MoveDir * 0.08f);
}

void MushroomN::MushroomGroundCheck(FVector2D _MovePos)
{
	IsGround = false;

	if (nullptr != ColImage)
	{
		// 픽셀충돌에서 제일 중요한건 애초에 박히지 않는것이다.
		FVector2D MushroomScale = MushroomRenderer->GetTransform().Scale;
		FVector2D NextPos = GetActorLocation() + FVector2D{ 0, 22 } + _MovePos;

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

void MushroomN::Gravity(float _DeltaTime)
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

bool MushroomN::OnTheBlock(float _DeltaTime)
{
	std::vector<AActor*> SteppingBlock;
	bool IsOnTheBlock = CollisionComponent
		->Collision(static_cast<int>(ECollisionGroup::SquareBlock), SteppingBlock, GravityForce * _DeltaTime, 100);
	return IsOnTheBlock;
}

void MushroomN::Eaten()
{
	{
		AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead, FVector2D::ZERO);
		if (nullptr != Result)
		{
			Destroy();
		}
	}

	{
		AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerBody, FVector2D::ZERO);
		if (nullptr != Result)
		{
			Destroy();
		}
	}

	{
		AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerFoot, FVector2D::ZERO);
		if (nullptr != Result)
		{
			Destroy();
		}
	}
}


void MushroomN::TurnAround(FVector2D _MovePos)
{
	FVector2D MushroomPos = this->GetActorLocation();

	if (nullptr != ColImage)
	{
		// 미래의 몬스터 위치
		FVector2D NextPos = MushroomPos + FVector2D{ 28.0f * PosOrN, 0.0 } + _MovePos;

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

	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::SquareBlock);
	if (nullptr != Result)
	{
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

	//몬스터가 맵의 왼쪽 끝에 닿을 경우 방향 변경
	if (MushroomPos.X <= 0.0)
	{
		MoveDir = FVector2D::RIGHT;
		PosOrN = 1.0f;
	}
}

bool MushroomN::GetOutOfBox(float _DeltaTime)
{
	std::vector<AActor*> InsideOfBox;
	bool InTheBox = CollisionComponent
		->Collision(static_cast<int>(ECollisionGroup::MysteryBox), InsideOfBox, FVector2D::DOWN, 100);
	return InTheBox;
}


void MushroomN::RiseUp(float _DeltaTime)
{
	if (true == GetOutOfBox(_DeltaTime))
		AddActorLocation(FVector2D::UP * 0.25f);
}

