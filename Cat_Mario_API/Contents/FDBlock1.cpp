#include "PreCompile.h"
#include "FDBlock1.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>
#include <EngineCore/Level.h>

#include "Enum.h"
#include "MarioCat.h"

FDBlock1::FDBlock1()
{
	USpriteRenderer* BlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BlockRenderer->SetSprite("FDBlock1.png");
	BlockRenderer->SetOrder(ERenderOrder::PLAYER);
	BlockRenderer->SetComponentScale({ 176, 60 });
	
	{
		CollisionComponent1 = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent1->SetComponentScale({ 176, 60 });
		CollisionComponent1->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent1->SetCollisionType(ECollisionType::Rect);
	}
	{
		CollisionComponent2 = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent2->SetComponentScale({ 176, 60 });
		CollisionComponent2->SetCollisionGroup(ECollisionGroup::FDBlock);
		CollisionComponent2->SetCollisionType(ECollisionType::Rect);
	}

	DebugOn();
}

FDBlock1::~FDBlock1()
{
}

void FDBlock1::BeginPlay()
{
	Super::BeginPlay();
}

void FDBlock1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (IsFalling == true)
	{
		AddActorLocation(FVector2D::DOWN * 700.0f * _DeltaTime);
		KillTheCat();
	}
}

void FDBlock1::KillTheCat()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();

	AActor* Result = CollisionComponent2->CollisionOnce(ECollisionGroup::ColPlayer);
	if (nullptr != Result)
	{
		Player->IsCatKilled = true;
		Player->ChangeState(PlayerState::Dead);
	}
}
