#include "PreCompile.h"
#include "GBBrick.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "GParticleA.h"
#include "GParticleB.h"
#include "GParticleC.h"
#include "GParticleD.h"


GBBrick::GBBrick()
{
	USpriteRenderer* GBBrickRenderer = CreateDefaultSubObject<USpriteRenderer>();
	GBBrickRenderer->SetSprite("GBreakingBlock.png");
	GBBrickRenderer->SetOrder(ERenderOrder::BLOCK);
	GBBrickRenderer->SetComponentScale({ 60, 60 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	DebugOn();

}

GBBrick::~GBBrick()
{
}

void GBBrick::BeginPlay()
{
	Super::BeginPlay();
}

void GBBrick::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::BigBody);
	if (nullptr != Result)
	{
		ItsBroken();
	}
}

void GBBrick::ItsBroken()
{
	{
		FVector2D PresentPos = this->GetActorLocation();
		GParticleA* Particle = GetWorld()->SpawnActor<GParticleA>();
		Particle->SetActorLocation(PresentPos);
	}
	{
		FVector2D PresentPos = this->GetActorLocation();
		GParticleB* Particle = GetWorld()->SpawnActor<GParticleB>();
		Particle->SetActorLocation(PresentPos);
	}
	{
		FVector2D PresentPos = this->GetActorLocation();
		GParticleC* Particle = GetWorld()->SpawnActor<GParticleC>();
		Particle->SetActorLocation(PresentPos);
	}
	{
		FVector2D PresentPos = this->GetActorLocation();
		GParticleD* Particle = GetWorld()->SpawnActor<GParticleD>();
		Particle->SetActorLocation(PresentPos);
	}
	Broken = true;
	this->Destroy();
}
