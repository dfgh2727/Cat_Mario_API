#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class FireBallSwitch : public AActor
{
public:
	// constrcuter destructer
	FireBallSwitch();
	~FireBallSwitch();

	// delete Function
	FireBallSwitch(const FireBallSwitch& _Other) = delete;
	FireBallSwitch(FireBallSwitch&& _Other) noexcept = delete;
	FireBallSwitch& operator=(const FireBallSwitch& _Other) = delete;
	FireBallSwitch& operator=(FireBallSwitch&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	class FBPipe* ThePipe;
	U2DCollision* CollisionComponent;
};

