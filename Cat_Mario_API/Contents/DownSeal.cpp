#include "PreCompile.h"
#include "DownSeal.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>

#include "Enum.h"

DownSeal::DownSeal()
{
	USpriteRenderer* UpSealRenderer = CreateDefaultSubObject<USpriteRenderer>();
	UpSealRenderer->SetSprite("DownSeal.png");
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

DownSeal::~DownSeal()
{
}

void DownSeal::BeginPlay()
{
	Super::BeginPlay();
}

void DownSeal::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
