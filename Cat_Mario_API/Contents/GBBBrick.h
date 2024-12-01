#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class GBBBrick : public AActor
{
public:
	// constrcuter destructer
	GBBBrick();
	~GBBBrick();

	// delete Function
	GBBBrick(const GBBBrick& _Other) = delete;
	GBBBrick(GBBBrick&& _Other) noexcept = delete;
	GBBBrick& operator=(const GBBBrick& _Other) = delete;
	GBBBrick& operator=(GBBBrick&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ItsBroken();

protected:

private:

	class USpriteRenderer* GBBBrickRenderer;
	U2DCollision* CollisionComponent;

	bool Broken = false;
};

