#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class GBBBox : public AActor
{
public:
	// constrcuter destructer
	GBBBox();
	~GBBBox();

	// delete Function
	GBBBox(const GBBBox& _Other) = delete;
	GBBBox(GBBBox&& _Other) noexcept = delete;
	GBBBox& operator=(const GBBBox& _Other) = delete;
	GBBBox& operator=(GBBBox&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ItsBroken();

protected:

private:
	class USpriteRenderer* GBBBoxRenderer;
	U2DCollision* CollisionComponent;

	bool Broken = false;
};

