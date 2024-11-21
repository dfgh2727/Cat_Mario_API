#include "PreCompile.h"
#include "BParticleA.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>

#include "Enum.h"

BParticleA::BParticleA()
{
	BParticleRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BParticleRenderer->SetSprite("BParticle.png");
	BParticleRenderer->SetOrder(ERenderOrder::PLAYER);
	BParticleRenderer->SetComponentScale({ 20, 20 });
}

BParticleA::~BParticleA()
{
}

void BParticleA::BeginPlay()
{
	Super::BeginPlay();
}

void BParticleA::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Gravity(_DeltaTime);
	AddActorLocation(FVector2D{ -300.0f * _DeltaTime, -100.0f *_DeltaTime});
}

void BParticleA::Gravity(float _DeltaTime)
{
	AddActorLocation(GravityForce * _DeltaTime);
	GravityForce += FVector2D::DOWN * _DeltaTime * 1200.0f;
}