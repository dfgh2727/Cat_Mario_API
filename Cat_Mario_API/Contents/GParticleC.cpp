#include "PreCompile.h"
#include "GParticleC.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>
#include "Enum.h"

GParticleC::GParticleC()
{
	BParticleRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BParticleRenderer->SetSprite("BParticle.png");
	BParticleRenderer->SetOrder(ERenderOrder::PLAYER);
	BParticleRenderer->SetComponentScale({ 20, 20 });
}

GParticleC::~GParticleC()
{
}

void GParticleC::BeginPlay()
{
	Super::BeginPlay();
}

void GParticleC::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Gravity(_DeltaTime);
	AddActorLocation(FVector2D{ 400.0f * _DeltaTime, -300.0f * _DeltaTime });
}

void GParticleC::Gravity(float _DeltaTime)
{
	AddActorLocation(GravityForce * _DeltaTime);
	GravityForce += FVector2D::DOWN * _DeltaTime * 1200.0f;
}
