#include "PreCompile.h"
#include "BBreakingBlock.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "BParticleA.h"


BBreakingBlock::BBreakingBlock()
{
	USpriteRenderer* BBreakingBlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BBreakingBlockRenderer->SetSprite("BBreakingBlock.png");
	BBreakingBlockRenderer->SetOrder(ERenderOrder::OBJECT);
	BBreakingBlockRenderer->SetComponentScale({ 60, 60 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
		DebugOn();
	}

}

BBreakingBlock::~BBreakingBlock()
{
}

void BBreakingBlock::BeginPlay()
{
	Super::BeginPlay();
}

void BBreakingBlock::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead);
	if (nullptr != Result)
	{

		{
			FVector2D PresentPos = this->GetActorLocation();
			BParticleA* Particle = GetWorld()->SpawnActor<BParticleA>();
			Particle->SetActorLocation(PresentPos);
		}

		this->Destroy();
	}


}
