#include "PreCompile.h"
#include "StarBox.h"
#include "Star.h"

#include "Enum.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>



StarBox::StarBox()
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

StarBox::~StarBox()
{
}

void StarBox::BeginPlay()
{
	Super::BeginPlay();
}

void StarBox::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	BlockDisappear(_DeltaTime);

}

void StarBox::BlockDisappear(float _DeltaTime)
{
	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead);
	if (nullptr != Result)
	{
		MonsterShowUP();
		this->Destroy();
	}

}

void StarBox::MonsterShowUP()
{
	FVector2D PresentPos = this->GetActorLocation();
	UEngineWinImage* ColImageForStar = this->GetColImage();

	Star* TheMonster = GetWorld()->SpawnActor<Star>();
	TheMonster->SetActorLocation(PresentPos);
	TheMonster->ColImage = ColImageForStar;
}