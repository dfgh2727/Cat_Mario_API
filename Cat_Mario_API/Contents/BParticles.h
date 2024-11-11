#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class BParticles : public AActor
{
public:
	// constrcuter destructer
	BParticles();
	~BParticles();

	// delete Function
	BParticles(const BParticles& _Other) = delete;
	BParticles(BParticles&& _Other) noexcept = delete;
	BParticles& operator=(const BParticles& _Other) = delete;
	BParticles& operator=(BParticles&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void FallApart(float _DeltaTime);

protected:

private:

	class USpriteRenderer* BParticleRenderer;

};

