#include "PreCompile.h"
#include "FDBlock1.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>

#include "Enum.h"

FDBlock1::FDBlock1()
{
	USpriteRenderer* BlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BlockRenderer->SetSprite("FDBlock1.png");
	BlockRenderer->SetOrder(ERenderOrder::PLAYER);
	BlockRenderer->SetComponentScale({ 176, 60 });
	
	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 176, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	//{
	//	CollisionComponent = CreateDefaultSubObject<U2DCollision>();
	//	CollisionComponent->SetComponentScale({ 176, 60 });
	//	CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
	//	CollisionComponent->SetCollisionType(ECollisionType::Rect);
	//}

	DebugOn();
}

FDBlock1::~FDBlock1()
{
}

void FDBlock1::BeginPlay()
{
	Super::BeginPlay();
}

void FDBlock1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

