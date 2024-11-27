#include "PreCompile.h"
#include "FDBlock2.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>

#include "Enum.h"

FDBlock2::FDBlock2()
{
	USpriteRenderer* BlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BlockRenderer->SetSprite("FDBlock2.png");
	BlockRenderer->SetOrder(ERenderOrder::PLAYER);
	BlockRenderer->SetComponentScale({ 292, 110 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 292, 110 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}

	DebugOn();
}

FDBlock2::~FDBlock2()
{
}

void FDBlock2::BeginPlay()
{
	Super::BeginPlay();
}

void FDBlock2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}


