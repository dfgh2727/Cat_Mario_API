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
	CollisionComponent->SetCollisionGroup(ECollisionGroup::CoinBox);
	CollisionComponent->SetCollisionType(ECollisionType::Rect);

	DebugOn();
}

void CoinBox::BlockDisappear(float _DeltaTime)
{
	/*AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead);
	if (nullptr != Result)
	{
		CoinShowUP();
		this->Destroy();
	}*/
	std::vector<AActor*> HitTheBlock;
	bool IsHit = CollisionComponent
		->Collision(static_cast<int>(ECollisionGroup::PlayerHead), HitTheBlock, FVector2D::UP, 100);
	//if (IsHit = true)
	//{
	//	CoinShowUP();
	//	this->Destroy();
	//}
}

void CoinBox::CoinShowUP()
{
	FVector2D PresentPos = this->GetActorLocation();
	Coin* TheCoin = GetWorld()->SpawnActor<Coin>();
	TheCoin->SetActorLocation(PresentPos);
	AddActorLocation(FVector2D::UP * 0.25f);
}
