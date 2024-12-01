#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class FDBlock4 : public AActor
{
public:
	// constrcuter destructer
	FDBlock4();
	~FDBlock4();

	// delete Function
	FDBlock4(const FDBlock4& _Other) = delete;
	FDBlock4(FDBlock4&& _Other) noexcept = delete;
	FDBlock4& operator=(const FDBlock4& _Other) = delete;
	FDBlock4& operator=(FDBlock4&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void KillTheCat();
	bool IsFalling = false;

protected:

private:
	U2DCollision* CollisionComponent;

	bool BlockIsTouched = false;
};

