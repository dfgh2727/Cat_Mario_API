#include "PreCompile.h"
#include "GParticleB.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>
#include "Enum.h"

GParticleB::GParticleB()
{
	BParticleRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BParticleRenderer->SetSprite("GParticle.png");
	BParticleRenderer->SetOrder(ERenderOrder::PLAYER);
	BParticleRenderer->SetComponentScale({ 20, 20 });
}

GParticleB::~GParticleB()
{
}


void GParticleB::BeginPlay()
{
	Super::BeginPlay();
}

void GParticleB::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Gravity(_DeltaTime);
	AddActorLocation(FVector2D{ 300.0f * _DeltaTime, -100.0f * _DeltaTime });
}

void GParticleB::Gravity(float _DeltaTime)
{
	AddActorLocation(GravityForce * _DeltaTime);
	GravityForce += FVector2D::DOWN * _DeltaTime * 1200.0f;
}