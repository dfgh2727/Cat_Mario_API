#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class StarBox : public AMapActor
{
public:
	// constrcuter destructer
	StarBox();
	~StarBox();

	// delete Function
	StarBox(const StarBox& _Other) = delete;
	StarBox(StarBox&& _Other) noexcept = delete;
	StarBox& operator=(const StarBox& _Other) = delete;
	StarBox& operator=(StarBox&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void BlockDisappear(float _DeltaTime);
	void MonsterShowUP();

protected:

private:

};

