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

	QBlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	QBlockRenderer->SetSprite("QBlock.png");
	QBlockRenderer->SetOrder(ERenderOrder::BLOCK);
	QBlockRenderer->SetComponentScale({ 60, 60 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::CoinBox);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
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

	if (End == false)
	{
		InfiniteCoin(_DeltaTime);
		Time -= _DeltaTime;
	}

	if (Time <= 0.0f)
	{
		End = true;
	}
}

void InfiniteCoinBox::InfiniteCoin(float _DeltaTime)
{
	MarioCat* MainActor = GetWorld()->GetPawn<MarioCat>();
	FVector2D GForce = MainActor->GetGravityForce();
	FVector2D CatJumpPower = MainActor->GetJumpPower();

	if (CatJumpPower.Y * (-1.0f) >= GForce.Y)
	{
		AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead);
		if (nullptr != Result)
		{
			CoinTime += _DeltaTime;

			FVector2D PresentPos = this->GetActorLocation();
			Coin* TheCoin = GetWorld()->SpawnActor<Coin>();
			TheCoin->SetActorLocation(PresentPos);
			AddActorLocation(FVector2D::UP * 0.25f);

			if (CoinTime >= 0.5f)
			{
				TheCoin->Destroy();
			}
			
		}

	}
}