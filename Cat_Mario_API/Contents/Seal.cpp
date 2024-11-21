#include "PreCompile.h"
#include "Seal.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>

#include "Enum.h"

Seal::Seal()
{
	USpriteRenderer* SealRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SealRenderer->SetSprite("Seal.png");
	SealRenderer->SetOrder(ERenderOrder::PLAYER);
	SealRenderer->SetComponentScale({ 53, 78 });
	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 53, 78 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	DebugOn();
}

Seal::~Seal()
{
}

void Seal::BeginPlay()
{
	Super::BeginPlay();
}

void Seal::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}


