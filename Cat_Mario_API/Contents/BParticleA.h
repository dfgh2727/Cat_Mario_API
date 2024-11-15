#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
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

	void FallApart(float _DeltaTime);

protected:

private:

	class USpriteRenderer* BParticleARenderer;
	FVector2D MoveVec = FVector2D::ZERO;
};

