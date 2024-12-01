#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class FDBlock3 : public AActor
{
public:
	// constrcuter destructer
	FDBlock3();
	~FDBlock3();

	// delete Function
	FDBlock3(const FDBlock3& _Other) = delete;
	FDBlock3(FDBlock3&& _Other) noexcept = delete;
	FDBlock3& operator=(const FDBlock3& _Other) = delete;
	FDBlock3& operator=(FDBlock3&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Touched();
	void FallDown(float _DeltaTime);

protected:

private:
	U2DCollision* CollisionComponent;

	bool BlockIsTouched = false;
};

