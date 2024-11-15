#include "PreCompile.h"
#include "BParticleA.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>

BParticleA::BParticleA()
{
	BParticleARenderer = CreateDefaultSubObject<USpriteRenderer>();
	BParticleARenderer->SetSprite("BParticleA.png");
	BParticleARenderer->SetComponentScale({ 30, 30 });
}

BParticleA::~BParticleA()
{
}

void BParticleA::BeginPlay()
{

}

void BParticleA::Tick(float _DeltaTime)
{
	FVector2D MoveVec = {}
	AddActorLocation();
}

void BParticleA::FallApart(float _DeltaTime)
{
	FVector2D MoveVec ={}

}


