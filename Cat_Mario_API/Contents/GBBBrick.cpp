#include "PreCompile.h"
#include "GBBBrick.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "GParticleA.h"
#include "GParticleB.h"
#include "GParticleC.h"
#include "GParticleD.h"


GBBBrick::GBBBrick()
{
	USpriteRenderer* GBBBrickRenderer = CreateDefaultSubObject<USpriteRenderer>();
	GBBBrickRenderer->SetSprite("GBreakingBlock.png");
	GBBBrickRenderer->SetOrder(ERenderOrder::BLOCK);
	GBBBrickRenderer->SetComponentScale({ 60, 60 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	DebugOn();

}

GBBBrick::~GBBBrick()
{
}

void GBBBrick::BeginPlay()
{
	Super::BeginPlay();
}

void GBBBrick::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::BigBody);
	if (nullptr != Result)
	{
		ItsBroken();
	}
}

void GBBBrick::ItsBroken()
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
