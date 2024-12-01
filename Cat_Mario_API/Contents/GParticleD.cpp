#include "PreCompile.h"
#include "GParticleD.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>
#include "Enum.h"

GParticleD::GParticleD()
{
	BParticleRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BParticleRenderer->SetSprite("GParticle.png");
	BParticleRenderer->SetOrder(ERenderOrder::PLAYER);
	BParticleRenderer->SetComponentScale({ 20, 20 });
}

GParticleD::~GParticleD()
{
}

void GParticleD::BeginPlay()
{
	Super::BeginPlay();
}

void GParticleD::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Gravity(_DeltaTime);
	AddActorLocation(FVector2D{ -400.0f * _DeltaTime, -300.0f * _DeltaTime });
}

void GParticleD::Gravity(float _DeltaTime)
{
	AddActorLocation(GravityForce * _DeltaTime);
	GravityForce += FVector2D::DOWN * _DeltaTime * 1200.0f;
}