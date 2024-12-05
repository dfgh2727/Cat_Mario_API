#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class GBMarbleBlock2 : public AActor
{
public:
	// constrcuter destructer
	GBMarbleBlock2();
	~GBMarbleBlock2();

	// delete Function
	GBMarbleBlock2(const GBMarbleBlock2& _Other) = delete;
	GBMarbleBlock2(GBMarbleBlock2&& _Other) noexcept = delete;
	GBMarbleBlock2& operator=(const GBMarbleBlock2& _Other) = delete;
	GBMarbleBlock2& operator=(GBMarbleBlock2&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ItsBroken();

protected:

private:

	class USpriteRenderer* GBMarbleBlock2Renderer;
	U2DCollision* CollisionComponent;

	bool Broken = false;
};

