#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class BParticleB : public AActor
{
public:
	// constrcuter destructer
	BParticleB();
	~BParticleB();

	// delete Function
	BParticleB(const BParticleB& _Other) = delete;
	BParticleB(BParticleB&& _Other) noexcept = delete;
	BParticleB& operator=(const BParticleB& _Other) = delete;
	BParticleB& operator=(BParticleB&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Gravity(float _DeltaTime);

protected:

private:

	class USpriteRenderer* BParticleARenderer;
	FVector2D MoveVec = FVector2D::ZERO;
	FVector2D GravityForce = FVector2D::ZERO;
};

