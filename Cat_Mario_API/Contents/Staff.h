#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class Staff : public AActor
{
public:
	// constrcuter destructer
	Staff();
	~Staff();

	// delete Function
	Staff(const Staff& _Other) = delete;
	Staff(Staff&& _Other) noexcept = delete;
	Staff& operator=(const Staff& _Other) = delete;
	Staff& operator=(Staff&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void CatTouchedStaff();

protected:

private:
	
	U2DCollision* CollisionComponent1;
	U2DCollision* CollisionComponent2;
};

