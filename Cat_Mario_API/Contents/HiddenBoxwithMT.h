#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class HiddenBoxwithMT : public AMapActor
{
public:
	// constrcuter destructer
	HiddenBoxwithMT();
	~HiddenBoxwithMT();

	// delete Function
	HiddenBoxwithMT(const HiddenBoxwithMT& _Other) = delete;
	HiddenBoxwithMT(HiddenBoxwithMT&& _Other) noexcept = delete;
	HiddenBoxwithMT& operator=(const HiddenBoxwithMT& _Other) = delete;
	HiddenBoxwithMT& operator=(HiddenBoxwithMT&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void BlockDisappear(float _DeltaTime);
	void BlockShowUP();
	void MushroomShowUP();

protected:

private:
	class USpriteRenderer* SkyRenderer;
	U2DCollision* CollisionComponent;
};

