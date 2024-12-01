#include "PreCompile.h"
#include "FDBlock3.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>

#include "Enum.h"

FDBlock3::FDBlock3()
{
	USpriteRenderer* BlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BlockRenderer->SetSprite("FDBlock3.png");
	BlockRenderer->SetOrder(ERenderOrder::PLAYER);
	BlockRenderer->SetComponentScale({ 56, 108 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 56, 108 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}

	DebugOn();
}

FDBlock3::~FDBlock3()
{
}

void FDBlock3::BeginPlay()
{
	Super::BeginPlay();
}

void FDBlock3::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Touched();
	FallDown(_DeltaTime);
}

void FDBlock3::Touched()
{
	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::ColPlayer, FVector2D::ZERO);
	if (nullptr != Result)
	{
		BlockIsTouched = true;
	}
}

void FDBlock3::FallDown(float _DeltaTime)
{
	if (BlockIsTouched == true)
	{
		AddActorLocation(FVector2D::DOWN * _DeltaTime * 300.0f);
	}
}


