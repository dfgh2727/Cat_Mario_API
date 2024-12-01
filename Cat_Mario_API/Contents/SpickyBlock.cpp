#include "PreCompile.h"
#include "SpickyBlock.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>

SpickyBlock::SpickyBlock()
{
	USpriteRenderer* BBreakingBlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BBreakingBlockRenderer->SetSprite("SpickyBlock.png");
	BBreakingBlockRenderer->SetOrder(ERenderOrder::BLOCK);
	BBreakingBlockRenderer->SetComponentScale({ 92, 76 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 92, 76 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
}

SpickyBlock::~SpickyBlock()
{
}

void SpickyBlock::BeginPlay()
{
	Super::BeginPlay();
}

void SpickyBlock::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
