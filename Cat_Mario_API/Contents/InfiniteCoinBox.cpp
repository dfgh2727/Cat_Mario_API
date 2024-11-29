#include "PreCompile.h"
#include "InfiniteCoinBox.h"
#include "Enum.h"
#include "BNormalBlock.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "Coin.h"
#include "MarioCat.h"

InfiniteCoinBox::InfiniteCoinBox()
{
	BBreakingBlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BBreakingBlockRenderer->SetSprite("BNormalBlock.png");
	BBreakingBlockRenderer->SetOrder(ERenderOrder::BLOCK);
	BBreakingBlockRenderer->SetComponentScale({ 60, 60 });

	{
		CollisionComponent1 = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent1->SetComponentScale({ 60, 60 });
		CollisionComponent1->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent1->SetCollisionType(ECollisionType::Rect);
	}
	{
		CollisionComponent2 = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent2->SetComponentScale({ 60, 60 });
		CollisionComponent2->SetCollisionGroup(ECollisionGroup::CoinBox);
		CollisionComponent2->SetCollisionType(ECollisionType::Rect);
	}
	DebugOn();
}

InfiniteCoinBox::~InfiniteCoinBox()
{
}

void InfiniteCoinBox::BeginPlay()
{
	Super::BeginPlay();
}

void InfiniteCoinBox::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	TouchCheck();

	if (Touched == true && End == false)
	{
		CoinCycle += _DeltaTime;
		Time -= _DeltaTime;

		if (CoinCycle >= 0.08f)
		{
			InfiniteCoin(_DeltaTime);
			CoinCycle = 0.0f;
		}
	}

	if (Time <= 0.0f)
	{
		End = true;
	}
}

void InfiniteCoinBox::TouchCheck()
{
	MarioCat* MainActor = GetWorld()->GetPawn<MarioCat>();
	FVector2D GForce = MainActor->GetGravityForce();
	FVector2D CatJumpPower = MainActor->GetJumpPower();

	if (CatJumpPower.Y * (-1.0f) >= GForce.Y)
	{
		AActor* Result = CollisionComponent2->CollisionOnce(ECollisionGroup::PlayerHead);
		if (nullptr != Result)
		{
			Touched = true;
		}

	}
}

void InfiniteCoinBox::InfiniteCoin(float _DeltaTime)
{
	CoinTimeLimit += _DeltaTime;

	FVector2D PresentPos = this->GetActorLocation();
	Coin* TheCoin = GetWorld()->SpawnActor<Coin>();
	TheCoin->SetActorLocation(PresentPos);
	TheCoin->AddActorLocation(FVector2D::UP * 0.2f);

	if (CoinTimeLimit >= 0.3f)
	{
		TheCoin->Destroy();
	}
}