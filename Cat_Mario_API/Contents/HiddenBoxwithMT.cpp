#include "PreCompile.h"
#include "HiddenBoxwithMT.h"
#include "Enum.h"
#include "BNormalBlock.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "MarioCat.h"
#include "BNormalBlock.h"
#include "MushroomT.h"


HiddenBoxwithMT::HiddenBoxwithMT()
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

HiddenBoxwithMT::~HiddenBoxwithMT()
{
}

void HiddenBoxwithMT::BeginPlay()
{
	Super::BeginPlay();
}

void HiddenBoxwithMT::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void HiddenBoxwithMT::BlockDisappear(float _DeltaTime)
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
				BlockShowUP();
				MushroomShowUP();
				this->Destroy();
			}

		}
	}

}

void HiddenBoxwithMT::BlockShowUP()
{
	FVector2D PresentPos = this->GetActorLocation();
	BNormalBlock* TheBlock = GetWorld()->SpawnActor<BNormalBlock>();
	TheBlock->SetActorLocation(PresentPos);
}

void HiddenBoxwithMT::MushroomShowUP()
{
	FVector2D PresentPos = this->GetActorLocation();
	UEngineWinImage* ColImageForWC = this->GetColImage();

	MushroomT* TheMushroom = GetWorld()->SpawnActor<MushroomT>();
	TheMushroom->SetActorLocation(PresentPos);
	TheMushroom->ColImage = ColImageForWC;
}