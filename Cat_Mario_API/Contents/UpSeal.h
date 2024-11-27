#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class UpSeal : public AActor
{
public:
	// constrcuter destructer
	UpSeal();
	~UpSeal();

	// delete Function
	UpSeal(const UpSeal& _Other) = delete;
	UpSeal(UpSeal&& _Other) noexcept = delete;
	UpSeal& operator=(const UpSeal& _Other) = delete;
	UpSeal& operator=(UpSeal&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	U2DCollision* CollisionComponent;
};

