#include "PreCompile.h"
#include "BBreakingBlock.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>

BBreakingBlock::BBreakingBlock()
{
	BBreakingBlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BBreakingBlockRenderer->SetSprite("BBreakingBlock.png");
	BBreakingBlockRenderer->SetOrder(ERenderOrder::OBJECT);
	BBreakingBlockRenderer->SetComponentScale({ 60, 60 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({100, 100 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}

	DebugOn();


}

BBreakingBlock::~BBreakingBlock()
{
}

void BBreakingBlock::BeginPlay()
{

}

void BBreakingBlock::Tick(float _DeltaTime)
{

}
