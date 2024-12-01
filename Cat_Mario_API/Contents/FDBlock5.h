#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class FDBlock5 : public AActor
{
public:
	// constrcuter destructer
	FDBlock5();
	~FDBlock5();

	// delete Function
	FDBlock5(const FDBlock5& _Other) = delete;
	FDBlock5(FDBlock5&& _Other) noexcept = delete;
	FDBlock5& operator=(const FDBlock5& _Other) = delete;
	FDBlock5& operator=(FDBlock5&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void KillTheCat();
	bool IsFalling = false;

protected:

private:
	U2DCollision* CollisionComponent;

	bool BlockIsTouched = false;
};

