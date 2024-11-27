#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class SecondMapP2 : public AActor
{
public:
	// constrcuter destructer
	SecondMapP2();
	~SecondMapP2();

	// delete Function
	SecondMapP2(const SecondMapP2& _Other) = delete;
	SecondMapP2(SecondMapP2&& _Other) noexcept = delete;
	SecondMapP2& operator=(const SecondMapP2& _Other) = delete;
	SecondMapP2& operator=(SecondMapP2&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


protected:

private:
};

