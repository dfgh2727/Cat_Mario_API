#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class FlyingStick : public AActor
{
public:
	// constrcuter destructer
	FlyingStick();
	~FlyingStick();

	// delete Function
	FlyingStick(const FlyingStick& _Other) = delete;
	FlyingStick(FlyingStick&& _Other) noexcept = delete;
	FlyingStick& operator=(const FlyingStick& _Other) = delete;
	FlyingStick& operator=(FlyingStick&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	U2DCollision* CollisionComponent;

	float time = 2.0f;
};

