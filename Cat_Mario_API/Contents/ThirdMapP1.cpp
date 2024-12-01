#include "PreCompile.h"
#include "ThirdMapP1.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>

ThirdMapP1::ThirdMapP1()
{
	USpriteRenderer* ThirdMapP1Renderer = CreateDefaultSubObject<USpriteRenderer>();
	ThirdMapP1Renderer->SetSprite("3rdMapP1.png");
	ThirdMapP1Renderer->SetOrder(ERenderOrder::PIPE);
	ThirdMapP1Renderer->SetComponentScale({ 120, 116 });
	{
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 77, 116 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}

	DebugOn();
}

ThirdMapP1::~ThirdMapP1()
{
}

void ThirdMapP1::BeginPlay()
{
	Super::BeginPlay();
}

void ThirdMapP1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
