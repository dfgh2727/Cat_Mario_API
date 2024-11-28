#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class Cloud : public AActor
{
public:
	// constrcuter destructer
	Cloud();
	~Cloud();

	// delete Function
	Cloud(const Cloud& _Other) = delete;
	Cloud(Cloud&& _Other) noexcept = delete;
	Cloud& operator=(const Cloud& _Other) = delete;
	Cloud& operator=(Cloud&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ChangeFace();

protected:

private:
	class USpriteRenderer* MonsterRenderer;
	U2DCollision* CollisionComponent;
};

