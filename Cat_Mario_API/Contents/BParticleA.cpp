#include "PreCompile.h"
#include "BParticleA.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineBase/EngineRandom.h>

#include "Enum.h"

BParticleA::BParticleA()
{
	BParticleARenderer = CreateDefaultSubObject<USpriteRenderer>();
	BParticleARenderer->SetSprite("BParticle.png");
	BParticleARenderer->SetOrder(ERenderOrder::PLAYER);
	BParticleARenderer->SetComponentScale({ 20, 20 });
}

BParticleA::~BParticleA()
{
}

void BParticleA::BeginPlay()
{

}

void BParticleA::Tick(float _DeltaTime)
{
	FallApart(_DeltaTime);
}

void BParticleA::FallApart(float _DeltaTime)
{
	FVector2D MoveVec = { -0.1f, 0.2f};
	AddActorLocation(MoveVec);
}


