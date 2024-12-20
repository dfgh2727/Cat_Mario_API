#pragma once
#include <EngineCore/Actor.h>

// ���� :
class BParticleA : public AActor
{
public:
	// constrcuter destructer
	BParticleA();
	~BParticleA();

	// delete Function
	BParticleA(const BParticleA& _Other) = delete;
	BParticleA(BParticleA&& _Other) noexcept = delete;
	BParticleA& operator=(const BParticleA& _Other) = delete;
	BParticleA& operator=(BParticleA&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Gravity(float _DeltaTime);

protected:

private:

	class USpriteRenderer* BParticleRenderer;
	FVector2D MoveVec = FVector2D::ZERO;
	FVector2D GravityForce = FVector2D::ZERO;
};

