#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class FBPipe : public AActor
{
public:
	// constrcuter destructer
	FBPipe();
	~FBPipe();

	// delete Function
	FBPipe(const FBPipe& _Other) = delete;
	FBPipe(FBPipe&& _Other) noexcept = delete;
	FBPipe& operator=(const FBPipe& _Other) = delete;
	FBPipe& operator=(FBPipe&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void SelectTheLoop(float _DeltaTime);
	void ShootFB(float _DeltaTime);

	bool SwitchUp = false;

protected:

private:
	U2DCollision* CollisionComponent;
};

