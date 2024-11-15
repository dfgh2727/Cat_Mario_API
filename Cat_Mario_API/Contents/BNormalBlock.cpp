#include "PreCompile.h"
#include "BNormalBlock.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>

BNormalBlock::BNormalBlock()
{
	USpriteRenderer* BBreakingBlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BBreakingBlockRenderer->SetSprite("BNormalBlock.png");
	BBreakingBlockRenderer->SetOrder(ERenderOrder::OBJECT);
	BBreakingBlockRenderer->SetComponentScale({ 60, 60 });

	{
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
		DebugOn();
	}
}

BNormalBlock::~BNormalBlock()
{
}

void BNormalBlock::BeginPlay()
{
	Super::BeginPlay();
}

void BNormalBlock::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}