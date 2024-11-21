#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class BParticleD : public AActor
{
public:
	// constrcuter destructer
	BParticleD();
	~BParticleD();

	// delete Function
	BParticleD(const BParticleD& _Other) = delete;
	BParticleD(BParticleD&& _Other) noexcept = delete;
	BParticleD& operator=(const BParticleD& _Other) = delete;
	BParticleD& operator=(BParticleD&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Gravity(float _DeltaTime);

protected:

private:
	class USpriteRenderer* BParticleRenderer;
	FVector2D MoveVec = FVector2D::ZERO;
	FVector2D GravityForce = FVector2D::ZERO;
};

