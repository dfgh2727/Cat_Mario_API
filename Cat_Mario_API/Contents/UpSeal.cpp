#include "PreCompile.h"
#include "UpSeal.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>

#include "Enum.h"

UpSeal::UpSeal()
{
	USpriteRenderer* UpSealRenderer = CreateDefaultSubObject<USpriteRenderer>();
	UpSealRenderer->SetSprite("UpSeal.png");
	UpSealRenderer->SetOrder(ERenderOrder::PLAYER);
	UpSealRenderer->SetComponentScale({ 53, 78 });
	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 53, 78 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	DebugOn();
}

UpSeal::~UpSeal()
{
}

void UpSeal::BeginPlay()
{
	Super::BeginPlay();
}

void UpSeal::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}


