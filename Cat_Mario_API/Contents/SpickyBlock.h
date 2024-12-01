#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class SpickyBlock : public AActor
{
public:
	// constrcuter destructer
	SpickyBlock();
	~SpickyBlock();

	// delete Function
	SpickyBlock(const SpickyBlock& _Other) = delete;
	SpickyBlock(SpickyBlock&& _Other) noexcept = delete;
	SpickyBlock& operator=(const SpickyBlock& _Other) = delete;
	SpickyBlock& operator=(SpickyBlock&& _Other) noexcept = delete;


	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	U2DCollision* CollisionComponent;
};

