#include "PreCompile.h"
#include "FDBlock5.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>
#include <EngineCore/Level.h>

#include "Enum.h"
#include "MarioCat.h"

FDBlock5::FDBlock5()
{
	USpriteRenderer* BlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BlockRenderer->SetSprite("FDBlock5.png");
	BlockRenderer->SetOrder(ERenderOrder::PLAYER);
	BlockRenderer->SetComponentScale({ 176, 61 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 176, 61 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}

	DebugOn();
}

FDBlock5::~FDBlock5()
{
}

void FDBlock5::BeginPlay()
{
	Super::BeginPlay();
}

void FDBlock5::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (IsFalling == true)
	{
		AddActorLocation(FVector2D::DOWN * 550.0f * _DeltaTime);
		KillTheCat();
	}

}


void FDBlock5::KillTheCat()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();

	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::ColPlayer);
	if (nullptr != Result)
	{
		Player->IsCatKilled = true;
		Player->ChangeState(PlayerState::Dead);
	}
}

