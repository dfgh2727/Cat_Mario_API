#include "PreCompile.h"
#include "FDBlock4.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>
#include <EngineCore/Level.h>

#include "Enum.h"
#include "MarioCat.h"

FDBlock4::FDBlock4()
{
	USpriteRenderer* BlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BlockRenderer->SetSprite("FDBlock4.png");
	BlockRenderer->SetOrder(ERenderOrder::PLAYER);
	BlockRenderer->SetComponentScale({ 350, 59 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 350, 59 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::MonsterBody);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}

	DebugOn();
}

FDBlock4::~FDBlock4()
{
}

void FDBlock4::BeginPlay()
{
	Super::BeginPlay();
}

void FDBlock4::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (IsFalling == true)
	{
		AddActorLocation(FVector2D::DOWN * 550.0f * _DeltaTime);
		KillTheCat();
	}

}

void FDBlock4::KillTheCat()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();

	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::ColPlayer);
	if (nullptr != Result)
	{
		Player->IsCatKilled = true;
		Player->ChangeState(PlayerState::Dead);
	}
}

