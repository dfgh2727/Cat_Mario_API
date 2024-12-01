#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class GParticleA : public AActor
{
public:
	// constrcuter destructer
	GParticleA();
	~GParticleA();

	// delete Function
	GParticleA(const GParticleA& _Other) = delete;
	GParticleA(GParticleA&& _Other) noexcept = delete;
	GParticleA& operator=(const GParticleA& _Other) = delete;
	GParticleA& operator=(GParticleA&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Gravity(float _DeltaTime);

protected:

private:

	class USpriteRenderer* BParticleRenderer;
	FVector2D MoveVec = FVector2D::ZERO;
	FVector2D GravityForce = FVector2D::ZERO;
};

