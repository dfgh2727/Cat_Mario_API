#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class Coin : public AActor
{
public:
	// constrcuter destructer
	Coin();
	~Coin();

	// delete Function
	Coin(const Coin& _Other) = delete;
	Coin(Coin&& _Other) noexcept = delete;
	Coin& operator=(const Coin& _Other) = delete;
	Coin& operator=(Coin&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void RiseUp();

protected:

private:
	float Time = 0.0f;

};

