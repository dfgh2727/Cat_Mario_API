#include "PreCompile.h"
#include "BBreakingBlock.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "BParticleA.h"
#include "BParticleB.h"
#include "BParticleC.h"
#include "BParticleD.h"

#include "MarioCat.h"


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
	
	MarioCat* MainPlayer = GetWorld()->GetPawn< MarioCat>();
	FVector2D GForce = MainPlayer->GetGravityForce();
	FVector2D CatJumpPower = MainPlayer->GetJumpPower();

	if (CatJumpPower.Y * (-1.0f) >= GForce.Y)
	{
		AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead);
		if (nullptr != Result)
		{
			ItsBroken();
			BGMPlayer.SetVolume(0.5f);
			BGMPlayer = UEngineSound::Play("Breaking.MP3");
		}
	}
}

void BBreakingBlock::ItsBroken()
{
	{
		FVector2D PresentPos = this->GetActorLocation();
		BParticleA* Particle = GetWorld()->SpawnActor<BParticleA>();
		Particle->SetActorLocation(PresentPos);
	}
	{
		FVector2D PresentPos = this->GetActorLocation();
		BParticleB* Particle = GetWorld()->SpawnActor<BParticleB>();
		Particle->SetActorLocation(PresentPos);
	}
	{
		FVector2D PresentPos = this->GetActorLocation();
		BParticleC* Particle = GetWorld()->SpawnActor<BParticleC>();
		Particle->SetActorLocation(PresentPos);
	}
	{
		FVector2D PresentPos = this->GetActorLocation();
		BParticleD* Particle = GetWorld()->SpawnActor<BParticleD>();
		Particle->SetActorLocation(PresentPos);
	}
	Broken = true;
	this->Destroy();
}
