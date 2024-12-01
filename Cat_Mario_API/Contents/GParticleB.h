#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class GParticleB : public AActor
{
public:
	// constrcuter destructer
	GParticleB();
	~GParticleB();

	// delete Function
	GParticleB(const GParticleB& _Other) = delete;
	GParticleB(GParticleB&& _Other) noexcept = delete;
	GParticleB& operator=(const GParticleB& _Other) = delete;
	GParticleB& operator=(GParticleB&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Gravity(float _DeltaTime);

protected:

private:
	class USpriteRenderer* BParticleRenderer;
	FVector2D MoveVec = FVector2D::ZERO;
	FVector2D GravityForce = FVector2D::ZERO;
};

