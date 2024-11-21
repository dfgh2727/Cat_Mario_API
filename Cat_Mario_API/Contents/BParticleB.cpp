#include "PreCompile.h"
#include "BParticleB.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>
#include "Enum.h"

BParticleB::BParticleB()
{
	BParticleARenderer = CreateDefaultSubObject<USpriteRenderer>();
	BParticleARenderer->SetSprite("BParticle.png");
	BParticleARenderer->SetOrder(ERenderOrder::PLAYER);
	BParticleARenderer->SetComponentScale({ 20, 20 });
}

BParticleB::~BParticleB()
{
}


void BParticleB::BeginPlay()
{
	Super::BeginPlay();
}

void BParticleB::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Gravity(_DeltaTime);
	AddActorLocation(FVector2D{ 300.0f * _DeltaTime, -100.0f * _DeltaTime });
}

void BParticleB::Gravity(float _DeltaTime)
{
	AddActorLocation(GravityForce * _DeltaTime);
	GravityForce += FVector2D::DOWN * _DeltaTime * 1200.0f;
}