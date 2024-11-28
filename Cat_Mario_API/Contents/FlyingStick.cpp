#include "PreCompile.h"
#include "FlyingStick.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>

#include "Enum.h"

FlyingStick::FlyingStick()
{
	USpriteRenderer* UpSealRenderer = CreateDefaultSubObject<USpriteRenderer>();
	UpSealRenderer->SetSprite("FlyingStick.png");
	UpSealRenderer->SetOrder(ERenderOrder::PLAYER);
	UpSealRenderer->SetComponentScale({ 125, 13 });
	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 125, 13 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	DebugOn();
}

FlyingStick::~FlyingStick()
{
}

void FlyingStick::BeginPlay()
{
	Super::BeginPlay();
}

void FlyingStick::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
