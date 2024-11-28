#include "PreCompile.h"
#include "QBlockwithMushroomN.h"

#include "Enum.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "MushroomN.h"

QBlockwithMushroomN::QBlockwithMushroomN()
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

QBlockwithMushroomN::~QBlockwithMushroomN()
{
}

void QBlockwithMushroomN::BeginPlay()
{
	Super::BeginPlay();
}

void QBlockwithMushroomN::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	BlockDisappear(_DeltaTime);

}

void QBlockwithMushroomN::BlockDisappear(float _DeltaTime)
{
	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead);
	if (nullptr != Result)
	{
		MushroomShowUP();
		this->Destroy();
	}

}

void QBlockwithMushroomN::MushroomShowUP()
{
	FVector2D PresentPos = this->GetActorLocation();
	UEngineWinImage* ColImageForWC = this->GetColImage();

	MushroomN* TheMushroom = GetWorld()->SpawnActor<MushroomN>();
	TheMushroom->SetActorLocation(PresentPos);
	TheMushroom->ColImage = ColImageForWC;
}
