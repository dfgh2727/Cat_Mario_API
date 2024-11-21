#include "PreCompile.h"
#include "CoinBox.h"
#include "Enum.h"
#include "Coin.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

CoinBox::CoinBox()
{
	
}

CoinBox::~CoinBox()
{
}

void CoinBox::RenderCollisionComponent()
{
	CollisionComponent = CreateDefaultSubObject<U2DCollision>();
	CollisionComponent->SetComponentScale({ 60, 60 });
	CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
	CollisionComponent->SetCollisionType(ECollisionType::Rect);

	DebugOn();
}

void CoinBox::BlockDisappear()
{
	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead);
	if (nullptr != Result)
	{
		CoinShowUP();
		this->Destroy();
	}
}

void CoinBox::CoinShowUP()
{
	FVector2D PresentPos = this->GetActorLocation();
	Coin* TheCoin = GetWorld()->SpawnActor<Coin>();
	TheCoin->SetActorLocation(PresentPos);
	AddActorLocation(FVector2D::UP * 0.25f);
}
