#include "PreCompile.h"
#include "QBlockwithWC.h"
#include "WhiteCircle.h"

#include "Enum.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>


QBlockwithWC::QBlockwithWC()
{
	USpriteRenderer* QMarkRenderer = CreateDefaultSubObject<USpriteRenderer>();
	QMarkRenderer->SetSprite("QBlock.png");
	QMarkRenderer->SetOrder(ERenderOrder::BLOCK);
	QMarkRenderer->SetComponentScale({ 60, 60 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
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
	BlockDisappear(_DeltaTime);

}

void QBlockwithWC::BlockDisappear(float _DeltaTime)
{
	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead);
	if (nullptr != Result)
	{
		MonsterShowUP();
		this->Destroy();
	}
	
}

void QBlockwithWC::MonsterShowUP()
{
	FVector2D PresentPos = this->GetActorLocation();
	UEngineWinImage* ColImageForWC = this->GetColImage();

	WhiteCircle* TheMonster = GetWorld()->SpawnActor<WhiteCircle>();
	TheMonster->SetActorLocation(PresentPos);
	TheMonster->ColImage = ColImageForWC;
	AddActorLocation(FVector2D::UP * 0.25f);
}


