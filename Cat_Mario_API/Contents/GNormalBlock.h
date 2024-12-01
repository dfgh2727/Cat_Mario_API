#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class GNormalBlock : public AActor
{
public:
	// constrcuter destructer
	GNormalBlock();
	~GNormalBlock();

	// delete Function
	GNormalBlock(const GNormalBlock& _Other) = delete;
	GNormalBlock(GNormalBlock&& _Other) noexcept = delete;
	GNormalBlock& operator=(const GNormalBlock& _Other) = delete;
	GNormalBlock& operator=(GNormalBlock&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	U2DCollision* CollisionComponent;
};

