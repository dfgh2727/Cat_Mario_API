#include "PreCompile.h"
#include "UpStair.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "Enum.h"

UpStair::UpStair()
{
	USpriteRenderer* UpStairRenderer = CreateDefaultSubObject<USpriteRenderer>();
	UpStairRenderer->SetSprite("FlyingStick.png");
	UpStairRenderer->SetOrder(ERenderOrder::PROP);
	UpStairRenderer->SetComponentScale({ 200, 20 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 200, 20 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
}

UpStair::~UpStair()
{
}

void UpStair::BeginPlay()
{
	Super::BeginPlay();
}

void UpStair::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AddActorLocation(FVector2D::UP * 100.0f * _DeltaTime);
}