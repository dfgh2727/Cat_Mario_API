#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class InfiniteCoinBox : public AActor
{
public:
	// constrcuter destructer
	InfiniteCoinBox();
	~InfiniteCoinBox();

	// delete Function
	InfiniteCoinBox(const InfiniteCoinBox& _Other) = delete;
	InfiniteCoinBox(InfiniteCoinBox&& _Other) noexcept = delete;
	InfiniteCoinBox& operator=(const InfiniteCoinBox& _Other) = delete;
	InfiniteCoinBox& operator=(InfiniteCoinBox&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void TouchCheck();
	void InfiniteCoin(float _DeltaTime);

protected:

private:
	class USpriteRenderer* BBreakingBlockRenderer;
	U2DCollision* CollisionComponent1;
	U2DCollision* CollisionComponent2;

	bool Touched = false;
	bool End = false;
	float Time = 2.0f;
	float CoinCycle = 0.0f;
	float CoinTimeLimit = 0.0f;
};

