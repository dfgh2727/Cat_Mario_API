#include "PreCompile.h"
#include "GNormalBlock.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>

GNormalBlock::GNormalBlock()
{
	USpriteRenderer* BBreakingBlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BBreakingBlockRenderer->SetSprite("GNormalBlock.png");
	BBreakingBlockRenderer->SetOrder(ERenderOrder::BLOCK);
	BBreakingBlockRenderer->SetComponentScale({ 60, 60 });

	{
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::MysteryBox);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	DebugOn();
}

GNormalBlock::~GNormalBlock()
{
}

void GNormalBlock::BeginPlay()
{
	Super::BeginPlay();
}

void GNormalBlock::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}