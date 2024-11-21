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
	Super::BeginPlay();
}

void BParticleA::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Gravity(_DeltaTime);
	AddActorLocation(FVector2D{ -500.0f * _DeltaTime, -100.0f *_DeltaTime});
}

//void BParticleA::FallApart(float _DeltaTime)
//{
//	FVector2D MoveVec = { -0.1f, 0.2f};
//	AddActorLocation(MoveVec);
//
//}


void BParticleA::Gravity(float _DeltaTime)
{
	AddActorLocation(GravityForce * _DeltaTime);
	GravityForce += FVector2D::DOWN * _DeltaTime * 1200.0f;
}