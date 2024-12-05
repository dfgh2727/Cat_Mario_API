#include "PreCompile.h"
#include "QBlockwithMushroom.h"

#include "Enum.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "MushroomN.h"
#include "MushroomB.h"

QBlockwithMushroom::QBlockwithMushroom()
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

QBlockwithMushroom::~QBlockwithMushroom()
{
}

void QBlockwithMushroom::BeginPlay()
{
	Super::BeginPlay();
}

void QBlockwithMushroom::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	BlockDisappear(_DeltaTime);

}

void QBlockwithMushroom::BlockDisappear(float _DeltaTime)
{
	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead);
	if (nullptr != Result)
	{
		MushroomShowUP();
		this->Destroy();
	}

}

void QBlockwithMushroom::MushroomShowUP()
{
	FVector2D PresentPos = this->GetActorLocation();
	UEngineWinImage* ColImageForMushroom = this->GetColImage();

	if (ItsB == true)
	{
		MushroomB* TheMushroomB = GetWorld()->SpawnActor<MushroomB>();
		TheMushroomB->SetActorLocation(PresentPos);
		TheMushroomB->ColImage = ColImageForMushroom;
	}
	else
	{
		MushroomN* TheMushroomN = GetWorld()->SpawnActor<MushroomN>();
		TheMushroomN->SetActorLocation(PresentPos);
		TheMushroomN->ColImage = ColImageForMushroom;
	}
}
