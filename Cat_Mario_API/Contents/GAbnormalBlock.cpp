#include "PreCompile.h"
#include "GAbnormalBlock.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "SpickyBlock.h"

GAbnormalBlock::GAbnormalBlock()
{
	USpriteRenderer* BBreakingBlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BBreakingBlockRenderer->SetSprite("GTileBlock.png");
	BBreakingBlockRenderer->SetOrder(ERenderOrder::BLOCK);
	BBreakingBlockRenderer->SetComponentScale({ 60, 60 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
}

GAbnormalBlock::~GAbnormalBlock()
{
}

void GAbnormalBlock::BeginPlay()
{
	Super::BeginPlay();
}

void GAbnormalBlock::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::ColPlayer);
	if (nullptr != Result)
	{
		BlockShowUP();
		this->Destroy();
	}
}

void GAbnormalBlock::BlockShowUP()
{
	FVector2D PresentPos = this->GetActorLocation();
	SpickyBlock* TheBlock = GetWorld()->SpawnActor<SpickyBlock>();
	TheBlock->SetActorLocation(PresentPos + FVector2D{0.0f, -10.0f});
}