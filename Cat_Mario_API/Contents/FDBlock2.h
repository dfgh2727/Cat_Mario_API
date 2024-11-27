#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class FDBlock2 : public AActor
{
public:
	// constrcuter destructer
	FDBlock2();
	~FDBlock2();

	// delete Function
	FDBlock2(const FDBlock2& _Other) = delete;
	FDBlock2(FDBlock2&& _Other) noexcept = delete;
	FDBlock2& operator=(const FDBlock2& _Other) = delete;
	FDBlock2& operator=(FDBlock2&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	U2DCollision* CollisionComponent;
};

