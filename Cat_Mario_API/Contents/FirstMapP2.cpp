#include "PreCompile.h"
#include "FirstMapP2.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>

FirstMapP2::FirstMapP2()
{
	USpriteRenderer* FirstMapP1Renderer = CreateDefaultSubObject<USpriteRenderer>();
	FirstMapP1Renderer->SetSprite("1stMapP2.png");
	FirstMapP1Renderer->SetOrder(ERenderOrder::PIPE);
	FirstMapP1Renderer->SetComponentScale({ 120, 234 });
	{
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 102, 234 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
		DebugOn();
}

FirstMapP2::~FirstMapP2()
{
}

void FirstMapP2::BeginPlay()
{
	Super::BeginPlay();
}

void FirstMapP2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
