#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class DownStair : public AActor
{
public:
	// constrcuter destructer
	DownStair();
	~DownStair();

	// delete Function
	DownStair(const DownStair& _Other) = delete;
	DownStair(DownStair&& _Other) noexcept = delete;
	DownStair& operator=(const DownStair& _Other) = delete;
	DownStair& operator=(DownStair&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void GoFaster();
	static bool Faster;

protected:

private:
	U2DCollision* CollisionComponent;
};

