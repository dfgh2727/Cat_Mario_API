#include "PreCompile.h"
#include "FDBlock6.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>
#include <EngineCore/Level.h>

#include "Enum.h"
#include "MarioCat.h"

FDBlock6::FDBlock6()
{
	USpriteRenderer* BlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BlockRenderer->SetSprite("FDBlock6.png");
	BlockRenderer->SetOrder(ERenderOrder::PLAYER);
	BlockRenderer->SetComponentScale({ 525, 61 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 525, 61 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}

	DebugOn();
}

FDBlock6::~FDBlock6()
{
}

void FDBlock6::BeginPlay()
{
	Super::BeginPlay();
}

void FDBlock6::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (IsFalling == true)
	{
		AddActorLocation(FVector2D::DOWN * 550.0f * _DeltaTime);
		KillTheCat();
	}

}

void FDBlock6::KillTheCat()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();

	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::ColPlayer);
	if (nullptr != Result)
	{
		Player->IsCatKilled = true;
		Player->ChangeState(PlayerState::Dead);
	}
}
