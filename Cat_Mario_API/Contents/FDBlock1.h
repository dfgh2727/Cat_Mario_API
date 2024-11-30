#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class FDBlock1 : public AActor
{
public:
	// constrcuter destructer
	FDBlock1();
	~FDBlock1();

	// delete Function
	FDBlock1(const FDBlock1& _Other) = delete;
	FDBlock1(FDBlock1&& _Other) noexcept = delete;
	FDBlock1& operator=(const FDBlock1& _Other) = delete;
	FDBlock1& operator=(FDBlock1&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void KillTheCat();
	bool IsFalling = false;

protected:

private:
	U2DCollision* CollisionComponent1;
	U2DCollision* CollisionComponent2;
};

