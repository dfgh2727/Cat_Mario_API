#include "PreCompile.h"
#include "BBreakingBlock.h"

#include <EngineCore/SpriteRenderer.h>

BBreakingBlock::BBreakingBlock()
{
	BBreakingBlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BBreakingBlockRenderer->SetSprite("BBreakingBlock.png");
	BBreakingBlockRenderer->SetComponentScale({ 100, 100 });
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

