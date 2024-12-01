#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class FDBlock7 : public AActor
{
public:
	// constrcuter destructer
	FDBlock7();
	~FDBlock7();

	// delete Function
	FDBlock7(const FDBlock7& _Other) = delete;
	FDBlock7(FDBlock7&& _Other) noexcept = delete;
	FDBlock7& operator=(const FDBlock7& _Other) = delete;
	FDBlock7& operator=(FDBlock7&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Touched();
	void FallDown(float _DeltaTime);

protected:

private:
	U2DCollision* CollisionComponent;

	bool BlockIsTouched = false;
};

