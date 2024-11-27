#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class ColPipe : public AActor
{
public:
	// constrcuter destructer
	ColPipe();
	~ColPipe();

	// delete Function
	ColPipe(const ColPipe& _Other) = delete;
	ColPipe(ColPipe&& _Other) noexcept = delete;
	ColPipe& operator=(const ColPipe& _Other) = delete;
	ColPipe& operator=(ColPipe&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void CatCheck(float _DeltaTime);


protected:

private:
	U2DCollision* CollisionComponent1;
	U2DCollision* CollisionComponent2;
};

