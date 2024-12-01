#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class FDBlock6 : public AActor
{
public:
	// constrcuter destructer
	FDBlock6();
	~FDBlock6();

	// delete Function
	FDBlock6(const FDBlock6& _Other) = delete;
	FDBlock6(FDBlock6&& _Other) noexcept = delete;
	FDBlock6& operator=(const FDBlock6& _Other) = delete;
	FDBlock6& operator=(FDBlock6&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void KillTheCat();
	bool IsFalling = false;

protected:

private:
	U2DCollision* CollisionComponent;

	bool BlockIsTouched = false;
};

