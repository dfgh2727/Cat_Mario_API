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
	BBreakingBlockRenderer->SetOrder(ERenderOrder::BLOCK);
	BBreakingBlockRenderer->SetComponentScale({ 60, 60 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
		DebugOn();

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
			Particle = GetWorld()->SpawnActor<BParticleA>();
			Particle->SetActorLocation(PresentPos);
			//AddActorLocation(FVector2D{ -500.0f * _DeltaTime, -100.0f * _DeltaTime });
		}
		Broken = true;
		this->Destroy();
	}
	/*if (Broken == true)
	{
		Particle->AddActorLocation(FVector2D{ -500.0f * _DeltaTime, -100.0f * _DeltaTime });

	}*/

}
