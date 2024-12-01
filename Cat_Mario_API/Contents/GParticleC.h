#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class GParticleC : public AActor
{
public:
	// constrcuter destructer
	GParticleC();
	~GParticleC();

	// delete Function
	GParticleC(const GParticleC& _Other) = delete;
	GParticleC(GParticleC&& _Other) noexcept = delete;
	GParticleC& operator=(const GParticleC& _Other) = delete;
	GParticleC& operator=(GParticleC&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Gravity(float _DeltaTime);

protected:

private:
	class USpriteRenderer* BParticleRenderer;
	FVector2D MoveVec = FVector2D::ZERO;
	FVector2D GravityForce = FVector2D::ZERO;
};

