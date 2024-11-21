#include "PreCompile.h"
#include "BParticleC.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>
#include "Enum.h"

BParticleC::BParticleC()
{
	BParticleRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BParticleRenderer->SetSprite("BParticle.png");
	BParticleRenderer->SetOrder(ERenderOrder::PLAYER);
	BParticleRenderer->SetComponentScale({ 20, 20 });
}

BParticleC::~BParticleC()
{
}

void BParticleC::BeginPlay()
{
	Super::BeginPlay();
}

void BParticleC::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Gravity(_DeltaTime);
	AddActorLocation(FVector2D{ 400.0f * _DeltaTime, -300.0f * _DeltaTime });
}

void BParticleC::Gravity(float _DeltaTime)
{
	AddActorLocation(GravityForce * _DeltaTime);
	GravityForce += FVector2D::DOWN * _DeltaTime * 1200.0f;
}
