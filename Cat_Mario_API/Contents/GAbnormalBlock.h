#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class GAbnormalBlock : public AActor
{
public:
	// constrcuter destructer
	GAbnormalBlock();
	~GAbnormalBlock();

	// delete Function
	GAbnormalBlock(const GAbnormalBlock& _Other) = delete;
	GAbnormalBlock(GAbnormalBlock&& _Other) noexcept = delete;
	GAbnormalBlock& operator=(const GAbnormalBlock& _Other) = delete;
	GAbnormalBlock& operator=(GAbnormalBlock&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void BlockShowUP();

protected:

private:
	U2DCollision* CollisionComponent;
};

