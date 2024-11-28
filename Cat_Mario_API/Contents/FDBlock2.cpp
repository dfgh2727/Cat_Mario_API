#include "PreCompile.h"
#include "FDBlock2.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>

#include "Enum.h"

FDBlock2::FDBlock2()
{
	USpriteRenderer* BlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BlockRenderer->SetSprite("FDBlock2.png");
	BlockRenderer->SetOrder(ERenderOrder::PLAYER);
	BlockRenderer->SetComponentScale({ 292, 110 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 292, 110 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}

	DebugOn();
}

FDBlock2::~FDBlock2()
{
}

void FDBlock2::BeginPlay()
{
	Super::BeginPlay();
}

void FDBlock2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Touched();
	FallDown(_DeltaTime);
}

void FDBlock2::Touched()
{
	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::ColPlayer, FVector2D::ZERO);
	if (nullptr != Result)
	{
		BlockIsTouched = true;
	}
}
void FDBlock2::FallDown(float _DeltaTime)
{
	if (BlockIsTouched == true)
	{
		AddActorLocation(FVector2D::DOWN * _DeltaTime * 300.0f);
	}

}


