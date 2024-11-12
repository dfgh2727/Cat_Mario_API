#include "PreCompile.h"
#include "BBreakingBlock.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>


BBreakingBlock::BBreakingBlock()
{
	BBreakingBlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BBreakingBlockRenderer->SetSprite("BBreakingBlock.png");
	BBreakingBlockRenderer->SetOrder(ERenderOrder::OBJECT);
	BBreakingBlockRenderer->SetComponentScale({ 60, 60 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
		DebugOn();
	}

}

BBreakingBlock::~BBreakingBlock()
{
}

void BBreakingBlock::BeginPlay()
{
	Super::BeginPlay();
}

void BBreakingBlock::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown('R'))
	{
		UEngineDebug::SwitchIsDebug();
	}
}
