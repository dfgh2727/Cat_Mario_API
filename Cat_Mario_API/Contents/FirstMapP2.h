#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class FirstMapP2 : public AActor
{
public:
	// constrcuter destructer
	FirstMapP2();
	~FirstMapP2();

	// delete Function
	FirstMapP2(const FirstMapP2& _Other) = delete;
	FirstMapP2(FirstMapP2&& _Other) noexcept = delete;
	FirstMapP2& operator=(const FirstMapP2& _Other) = delete;
	FirstMapP2& operator=(FirstMapP2&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void CatInthePipe();
	void PipeMotion(float _DeltaTime);
	void Shake(float _DeltaTime);
	void Launch(float _DeltaTime);

protected:

private:
	bool ShakeThePipe = false;
	float ShakingTime = 0.0f;
	float Time = 0.0f;
};

