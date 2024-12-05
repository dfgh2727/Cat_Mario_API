#include "PreCompile.h"
#include "GBTileBlock.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "GParticleA.h"
#include "GParticleB.h"
#include "GParticleC.h"
#include "GParticleD.h"


GBTileBlock::GBTileBlock()
{
	USpriteRenderer* GBTileBlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	GBTileBlockRenderer->SetSprite("GTileBlock.png");
	GBTileBlockRenderer->SetOrder(ERenderOrder::BLOCK);
	GBTileBlockRenderer->SetComponentScale({ 60, 60 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	DebugOn();

}

GBTileBlock::~GBTileBlock()
{
}

void GBTileBlock::BeginPlay()
{
	Super::BeginPlay();
}

void GBTileBlock::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::BigBody);
	if (nullptr != Result)
	{
		ItsBroken();
	}
}

void GBTileBlock::ItsBroken()
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
