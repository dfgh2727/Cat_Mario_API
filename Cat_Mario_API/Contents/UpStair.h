#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class UpStair : public AActor
{
public:
	// constrcuter destructer
	UpStair();
	~UpStair();

	// delete Function
	UpStair(const UpStair& _Other) = delete;
	UpStair(UpStair&& _Other) noexcept = delete;
	UpStair& operator=(const UpStair& _Other) = delete;
	UpStair& operator=(UpStair&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	U2DCollision* CollisionComponent;
};

