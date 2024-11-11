#include "PreCompile.h"
#include "BParticles.h"

#include <EngineCore/SpriteRenderer.h>

BParticles::BParticles()
{
	BParticleRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BParticleRenderer->SetSprite("BParticle.png");
	BParticleRenderer->SetComponentScale({ 30, 30 });
}

BParticles::~BParticles()
{
}

void BParticles::BeginPlay()
{

}

void BParticles::Tick(float _DeltaTime)
{

}

void FallApart(float _DeltaTime)
{


}

