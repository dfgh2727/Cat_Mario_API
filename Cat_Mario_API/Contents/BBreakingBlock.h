#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>
#include <EnginePlatform/EngineSound.h>

// Ό³Έν :
class BBreakingBlock : public AActor
{
public:
	// constrcuter destructer
	BBreakingBlock();
	~BBreakingBlock();

	// delete Function
	BBreakingBlock(const BBreakingBlock& _Other) = delete;
	BBreakingBlock(BBreakingBlock&& _Other) noexcept = delete;
	BBreakingBlock& operator=(const BBreakingBlock& _Other) = delete;
	BBreakingBlock& operator=(BBreakingBlock&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ItsBroken();

protected:

private:
	U2DCollision* CollisionComponent;

	bool Broken = false;
	USoundPlayer BGMPlayer;
};

