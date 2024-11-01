#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class MarioCat : public AActor
{
public:
	// constrcuter destructer
	MarioCat();
	~MarioCat();

	// delete Function
	MarioCat(const MarioCat& _Other) = delete;
	MarioCat(MarioCat&& _Other) noexcept = delete;
	MarioCat& operator=(const MarioCat& _Other) = delete;
	MarioCat& operator=(MarioCat&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	/*void CatController();*/

protected:

private:
	float Speed = 100.0f;

};

