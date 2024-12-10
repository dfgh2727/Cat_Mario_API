#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class FakeStaff : public AActor
{
public:
	// constrcuter destructer
	FakeStaff();
	~FakeStaff();

	// delete Function
	FakeStaff(const FakeStaff& _Other) = delete;
	FakeStaff(FakeStaff&& _Other) noexcept = delete;
	FakeStaff& operator=(const FakeStaff& _Other) = delete;
	FakeStaff& operator=(FakeStaff&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	U2DCollision* CollisionComponent1;
	U2DCollision* CollisionComponent2;
};

