#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class Seal : public AActor
{
public:
	// constrcuter destructer
	Seal();
	~Seal();

	// delete Function
	Seal(const Seal& _Other) = delete;
	Seal(Seal&& _Other) noexcept = delete;
	Seal& operator=(const Seal& _Other) = delete;
	Seal& operator=(Seal&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	class USpriteRenderer* MonsterRenderer;
	U2DCollision* MonsterBody;
	U2DCollision* CollisionComponent;
};

