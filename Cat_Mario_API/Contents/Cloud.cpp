#include "PreCompile.h"
#include "Cloud.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>

#include "Enum.h"

Cloud::Cloud()
{
	USpriteRenderer* UpSealRenderer = CreateDefaultSubObject<USpriteRenderer>();
	UpSealRenderer->SetSprite("Cloud_Calm.png");
	UpSealRenderer->SetOrder(ERenderOrder::PLAYER);
	UpSealRenderer->SetComponentScale({ 140, 80 });
	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 140, 80 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	DebugOn();
}

Cloud::~Cloud()
{
}

void Cloud::BeginPlay()
{
	Super::BeginPlay();
}

void Cloud::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}


