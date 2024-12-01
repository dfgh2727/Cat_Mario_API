#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class ThirdMapP1 : public AActor
{
public:
	// constrcuter destructer
	ThirdMapP1();
	~ThirdMapP1();

	// delete Function
	ThirdMapP1(const ThirdMapP1& _Other) = delete;
	ThirdMapP1(ThirdMapP1&& _Other) noexcept = delete;
	ThirdMapP1& operator=(const ThirdMapP1& _Other) = delete;
	ThirdMapP1& operator=(ThirdMapP1&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:

};

