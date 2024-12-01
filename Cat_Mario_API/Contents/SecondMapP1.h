#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class SecondMapP1 : public AActor
{
public:
	// constrcuter destructer
	SecondMapP1();
	~SecondMapP1();

	// delete Function
	SecondMapP1(const SecondMapP1& _Other) = delete;
	SecondMapP1(SecondMapP1&& _Other) noexcept = delete;
	SecondMapP1& operator=(const SecondMapP1& _Other) = delete;
	SecondMapP1& operator=(SecondMapP1&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	U2DCollision* CollisionComponent1;
	U2DCollision* CollisionComponent2;


};

