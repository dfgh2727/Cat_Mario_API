#include "PreCompile.h"
#include "Cloud.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>

#include "Enum.h"

Cloud::Cloud()
{
	MonsterRenderer = CreateDefaultSubObject<USpriteRenderer>();
	MonsterRenderer->SetSprite("Cloud_Calm.png");
	MonsterRenderer->SetOrder(ERenderOrder::PLAYER);
	MonsterRenderer->SetComponentScale({ 140, 80 });
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

	ChangeFace();
}

void Cloud::ChangeFace()
{
	{
		AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead, FVector2D::ZERO);
		if (nullptr != Result)
		{
			MonsterRenderer->SetSprite("Cloud_Angry.png");
		}
	}

	{
		AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerBody, FVector2D::ZERO);
		if (nullptr != Result)
		{
			MonsterRenderer->SetSprite("Cloud_Angry.png");
		}
	}

	{
		AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerFoot, FVector2D::ZERO);
		if (nullptr != Result)
		{
			MonsterRenderer->SetSprite("Cloud_Angry.png");
		}
	}
}


