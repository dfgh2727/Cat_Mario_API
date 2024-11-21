#include "PreCompile.h"
#include "PipeHead.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>

PipeHead::PipeHead()
{
	USpriteRenderer* PipeHeadRenderer = CreateDefaultSubObject<USpriteRenderer>();
	PipeHeadRenderer->SetSprite("PipeHead.png");
	PipeHeadRenderer->SetOrder(ERenderOrder::BLOCK);
	PipeHeadRenderer->SetComponentScale({ 120, 60 });

	{
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 120, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
		DebugOn();
}

PipeHead::~PipeHead()
{
}

void PipeHead::BeginPlay()
{
	Super::BeginPlay();
}

void PipeHead::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

