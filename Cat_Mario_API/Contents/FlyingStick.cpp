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
	UpSealRenderer->SetComponentScale({ 200, 25 });
	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 200, 25 });
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

	AddActorLocation(FVector2D::LEFT * _DeltaTime * 900.0f);

	time -= _DeltaTime;

	if (time <= 0.0f)
	{
		this->Destroy();
	}
}
