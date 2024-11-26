#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class DownSeal : public AActor
{
public:
	// constrcuter destructer
	DownSeal();
	~DownSeal();

	// delete Function
	DownSeal(const DownSeal& _Other) = delete;
	DownSeal(DownSeal&& _Other) noexcept = delete;
	DownSeal& operator=(const DownSeal& _Other) = delete;
	DownSeal& operator=(DownSeal&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	class USpriteRenderer* MonsterRenderer;
	U2DCollision* MonsterBody;
	U2DCollision* CollisionComponent;
};

