#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class BParticleC : public AActor
{
public:
	// constrcuter destructer
	BParticleC();
	~BParticleC();

	// delete Function
	BParticleC(const BParticleC& _Other) = delete;
	BParticleC(BParticleC&& _Other) noexcept = delete;
	BParticleC& operator=(const BParticleC& _Other) = delete;
	BParticleC& operator=(BParticleC&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Gravity(float _DeltaTime);

protected:

private:
	class USpriteRenderer* BParticleRenderer;
	FVector2D MoveVec = FVector2D::ZERO;
	FVector2D GravityForce = FVector2D::ZERO;
};

