#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class FirstMapP1 : public AActor
{
public:
	// constrcuter destructer
	FirstMapP1();
	~FirstMapP1();

	// delete Function
	FirstMapP1(const FirstMapP1& _Other) = delete;
	FirstMapP1(FirstMapP1&& _Other) noexcept = delete;
	FirstMapP1& operator=(const FirstMapP1& _Other) = delete;
	FirstMapP1& operator=(FirstMapP1&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Launch()

protected:

private:
	
};

