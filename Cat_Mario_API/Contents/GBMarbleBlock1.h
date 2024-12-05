#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class GBMarbleBlock1 : public AActor
{
public:
	// constrcuter destructer
	GBMarbleBlock1();
	~GBMarbleBlock1();

	// delete Function
	GBMarbleBlock1(const GBMarbleBlock1& _Other) = delete;
	GBMarbleBlock1(GBMarbleBlock1&& _Other) noexcept = delete;
	GBMarbleBlock1& operator=(const GBMarbleBlock1& _Other) = delete;
	GBMarbleBlock1& operator=(GBMarbleBlock1&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ItsBroken();

protected:

private:

	class USpriteRenderer* GBMarbleBlock1Renderer;
	U2DCollision* CollisionComponent;

	bool Broken = false;
};

