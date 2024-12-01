#include "PreCompile.h"
#include "FDBlock7.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>

#include "Enum.h"

FDBlock7::FDBlock7()
{
	USpriteRenderer* BlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BlockRenderer->SetSprite("FDBlock7.png");
	BlockRenderer->SetOrder(ERenderOrder::PLAYER);
	BlockRenderer->SetComponentScale({ 292, 342 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 292, 342 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}

	DebugOn();
}

FDBlock7::~FDBlock7()
{
}

void FDBlock7::BeginPlay()
{
	Super::BeginPlay();
}

void FDBlock7::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Touched();
	FallDown(_DeltaTime);
}

void FDBlock7::Touched()
{
	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::ColPlayer, FVector2D::ZERO);
	if (nullptr != Result)
	{
		BlockIsTouched = true;
	}
}
void FDBlock7::FallDown(float _DeltaTime)
{
	if (BlockIsTouched == true)
	{
		AddActorLocation(FVector2D::DOWN * _DeltaTime * 300.0f);
	}

}


