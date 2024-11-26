#include "PreCompile.h"
#include "HiddenBoxS.h"
#include "Enum.h"
#include "BNormalBlock.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>
#include"MarioCat.h"

HiddenBoxS::HiddenBoxS()
{
	SkyRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SkyRenderer->SetSprite("SkyBlock.png");
	SkyRenderer->SetOrder(ERenderOrder::HIDDEN);
	SkyRenderer->SetComponentScale({ 60, 60 });

	CollisionComponent = CreateDefaultSubObject<U2DCollision>();
	CollisionComponent->SetComponentScale({ 60, 60 });
	CollisionComponent->SetCollisionGroup(ECollisionGroup::CoinBox);
	CollisionComponent->SetCollisionType(ECollisionType::Rect);

	DebugOn();
}

HiddenBoxS::~HiddenBoxS()
{
}

void HiddenBoxS::BeginPlay()
{
	Super::BeginPlay();
}

void HiddenBoxS::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	BlockDisappear(_DeltaTime);

	AActor* MainActor = GetWorld()->GetPawn();
	
}

void HiddenBoxS::BlockDisappear(float _DeltaTime)
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

void HiddenBoxS::BlockShowUP()
{
	FVector2D PresentPos = this->GetActorLocation();
	BNormalBlock* TheBlock = GetWorld()->SpawnActor<BNormalBlock>();
	TheBlock->SetActorLocation(PresentPos);
}
