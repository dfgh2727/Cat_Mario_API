#include "PreCompile.h"
#include "GBMarbleBlock1.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "GParticleA.h"
#include "GParticleB.h"
#include "GParticleC.h"
#include "GParticleD.h"


GBMarbleBlock1::GBMarbleBlock1()
{
	USpriteRenderer* GBMarbleBlock1Renderer = CreateDefaultSubObject<USpriteRenderer>();
	GBMarbleBlock1Renderer->SetSprite("GMarbleBlock1.png");
	GBMarbleBlock1Renderer->SetOrder(ERenderOrder::BLOCK);
	GBMarbleBlock1Renderer->SetComponentScale({ 60, 60 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	DebugOn();

}

GBMarbleBlock1::~GBMarbleBlock1()
{
}

void GBMarbleBlock1::BeginPlay()
{
	Super::BeginPlay();
}

void GBMarbleBlock1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::BigBody);
	if (nullptr != Result)
	{
		ItsBroken();
	}
}

void GBMarbleBlock1::ItsBroken()
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
