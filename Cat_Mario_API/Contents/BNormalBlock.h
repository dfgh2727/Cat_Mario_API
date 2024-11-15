#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class BNormalBlock : public AActor
{
public:
	// constrcuter destructer
	BNormalBlock();
	~BNormalBlock();

	// delete Function
	BNormalBlock(const BNormalBlock& _Other) = delete;
	BNormalBlock(BNormalBlock&& _Other) noexcept = delete;
	BNormalBlock& operator=(const BNormalBlock& _Other) = delete;
	BNormalBlock& operator=(BNormalBlock&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:

	class USpriteRenderer* BBreakingBlockRenderer;
	U2DCollision* CollisionComponent;
};

