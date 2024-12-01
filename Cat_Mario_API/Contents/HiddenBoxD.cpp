#include "PreCompile.h"
#include "HiddenBoxD.h"
#include "Enum.h"
#include "GNormalBlock.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>
#include"MarioCat.h"

HiddenBoxD::HiddenBoxD()
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

HiddenBoxD::~HiddenBoxD()
{
}

void HiddenBoxD::BeginPlay()
{
	Super::BeginPlay();
}

void HiddenBoxD::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	BlockDisappear(_DeltaTime);
}

void HiddenBoxD::BlockDisappear(float _DeltaTime)
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

void HiddenBoxD::BlockShowUP()
{
	FVector2D PresentPos = this->GetActorLocation();
	GNormalBlock* TheBlock = GetWorld()->SpawnActor<GNormalBlock>();
	TheBlock->SetActorLocation(PresentPos);
}
