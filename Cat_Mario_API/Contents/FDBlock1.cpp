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
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 176, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	{
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 176, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::FDBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
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
	}
}

