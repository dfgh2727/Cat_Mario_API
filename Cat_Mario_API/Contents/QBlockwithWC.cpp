#include "PreCompile.h"
#include "QBlockwithWC.h"
#include "Enum.h"
#include "WhiteCircle.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>


QBlockwithWC::QBlockwithWC()
{
	USpriteRenderer* QBlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	QBlockRenderer->SetSprite("QBlock.png");
	QBlockRenderer->SetOrder(ERenderOrder::BLOCK);
	QBlockRenderer->SetComponentScale({ 60, 60 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::CoinBox);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}

	DebugOn();
}

QBlockwithWC::~QBlockwithWC()
{
}

void QBlockwithWC::BeginPlay()
{
	Super::BeginPlay();
}

void QBlockwithWC::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
//void QBlockwithWC::BlockDisappear(float _DeltaTime)
//{
//	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead);
//	if (nullptr != Result)
//	{
//		CoinShowUP();
//		this->Destroy();
//	}
//	
//}

//void QBlockwithWC::CoinShowUP()
//{
//	FVector2D PresentPos = this->GetActorLocation();
//	WhiteCircle* TheMonster = GetWorld()->SpawnActor<WhiteCircle>();
//	TheCoin->SetActorLocation(PresentPos);
//	AddActorLocation(FVector2D::UP * 0.25f);
//}


