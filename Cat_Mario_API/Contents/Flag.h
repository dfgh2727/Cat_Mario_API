#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// ���� :
class Flag : public AActor
{
public:
	// constrcuter destructer
	Flag();
	~Flag();

	// delete Function
	Flag(const Flag& _Other) = delete;
	Flag(Flag&& _Other) noexcept = delete;
	Flag& operator=(const Flag& _Other) = delete;
	Flag& operator=(Flag&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	U2DCollision* CollisionComponent;
};

