#include "PreCompile.h"
#include "BBreakingBlock.h"

#include <EngineCore/SpriteRenderer.h>

BBreakingBlock::BBreakingBlock()
{
	BBreakingBlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BBreakingBlockRenderer->SetSprite("BBreakingBlock.png");
	BBreakingBlockRenderer->SetComponentScale({ 60, 60 });

	SetActorLocation({ 726, 528 });

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

