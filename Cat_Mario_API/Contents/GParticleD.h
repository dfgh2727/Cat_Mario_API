#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class GParticleD : public AActor
{
public:
	// constrcuter destructer
	GParticleD();
	~GParticleD();

	// delete Function
	GParticleD(const GParticleD& _Other) = delete;
	GParticleD(GParticleD&& _Other) noexcept = delete;
	GParticleD& operator=(const GParticleD& _Other) = delete;
	GParticleD& operator=(GParticleD&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Gravity(float _DeltaTime);

protected:

private:
	class USpriteRenderer* BParticleRenderer;
	FVector2D MoveVec = FVector2D::ZERO;
	FVector2D GravityForce = FVector2D::ZERO;
};

