#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class ColPipe2 : public AActor
{
public:
	// constrcuter destructer
	ColPipe2();
	~ColPipe2();

	// delete Function
	ColPipe2(const ColPipe2& _Other) = delete;
	ColPipe2(ColPipe2&& _Other) noexcept = delete;
	ColPipe2& operator=(const ColPipe2& _Other) = delete;
	ColPipe2& operator=(ColPipe2&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void CatCheck(float _DeltaTime);


protected:

private:
	U2DCollision* CollisionComponent1;
	U2DCollision* CollisionComponent2;
};

