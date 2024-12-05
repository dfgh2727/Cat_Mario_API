#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class GBBrick : public AActor
{
public:
	// constrcuter destructer
	GBBrick();
	~GBBrick();

	// delete Function
	GBBrick(const GBBrick& _Other) = delete;
	GBBrick(GBBrick&& _Other) noexcept = delete;
	GBBrick& operator=(const GBBrick& _Other) = delete;
	GBBrick& operator=(GBBrick&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ItsBroken();

protected:

private:

	class USpriteRenderer* GBBrickRenderer;
	U2DCollision* CollisionComponent;

	bool Broken = false;
};

