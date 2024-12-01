#include "PreCompile.h"
#include "HiddenBoxFragile.h"
#include "Enum.h"
#include "GBBBox.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>
#include"MarioCat.h"

HiddenBoxFragile::HiddenBoxFragile()
{
	DarkRenderer = CreateDefaultSubObject<USpriteRenderer>();
	DarkRenderer->SetSprite("DarkBlock.png");
	DarkRenderer->SetOrder(ERenderOrder::HIDDEN);
	DarkRenderer->SetComponentScale({ 60, 60 });

	CollisionComponent = CreateDefaultSubObject<U2DCollision>();
	CollisionComponent->SetComponentScale({ 60, 60 });
	CollisionComponent->SetCollisionGroup(ECollisionGroup::CoinBox);
	CollisionComponent->SetCollisionType(ECollisionType::Rect);

	DebugOn();
}

HiddenBoxFragile::~HiddenBoxFragile()
{
}

void HiddenBoxFragile::BeginPlay()
{
	Super::BeginPlay();
}

void HiddenBoxFragile::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	BlockDisappear(_DeltaTime);
}

void HiddenBoxFragile::BlockDisappear(float _DeltaTime)
{
	MarioCat* MainActor = GetWorld()->GetPawn<MarioCat>();
	FVector2D GForce = MainActor->GetGravityForce();
	FVector2D CatJumpPower = MainActor->GetJumpPower();

	if (MainActor->GetPlayerState() == PlayerState::Jump)
	{
		if (CatJumpPower.Y * (-1.0f) >= GForce.Y)
		{
			AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead);
			if (nullptr != Result)
			{
				CoinShowUP();
				BlockShowUP();
				this->Destroy();
			}

		}
	}
}

void HiddenBoxFragile::BlockShowUP()
{
	FVector2D PresentPos = this->GetActorLocation();
	GBBBox* TheBlock = GetWorld()->SpawnActor<GBBBox>();
	TheBlock->SetActorLocation(PresentPos);
}
