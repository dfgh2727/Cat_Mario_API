#include "PreCompile.h"
#include "GBBBox.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "GParticleA.h"
#include "GParticleB.h"
#include "GParticleC.h"
#include "GParticleD.h"

#include "MarioCat.h"


GBBBox::GBBBox()
{
	USpriteRenderer* GBBBoxRenderer = CreateDefaultSubObject<USpriteRenderer>();
	GBBBoxRenderer->SetSprite("GNormalBlock.png");
	GBBBoxRenderer->SetOrder(ERenderOrder::BLOCK);
	GBBBoxRenderer->SetComponentScale({ 60, 60 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	DebugOn();

}

GBBBox::~GBBBox()
{
}

void GBBBox::BeginPlay()
{
	Super::BeginPlay();
}

void GBBBox::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	MarioCat* MainPlayer = GetWorld()->GetPawn< MarioCat>();
	FVector2D GForce = MainPlayer->GetGravityForce();
	FVector2D CatJumpPower = MainPlayer->GetJumpPower();

	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::ColPlayer);
	if (nullptr != Result)
	{
		ItsBroken();
	}
}

void GBBBox::ItsBroken()
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
