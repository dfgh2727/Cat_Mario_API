#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class ThirdMapP2 : public AActor
{
public:
	// constrcuter destructer
	ThirdMapP2();
	~ThirdMapP2();

	// delete Function
	ThirdMapP2(const ThirdMapP2& _Other) = delete;
	ThirdMapP2(ThirdMapP2&& _Other) noexcept = delete;
	ThirdMapP2& operator=(const ThirdMapP2& _Other) = delete;
	ThirdMapP2& operator=(ThirdMapP2&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


protected:

private:
};

