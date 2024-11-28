#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class MushroomN : public AMapActor
{
public:
	// constrcuter destructer
	MushroomN();
	~MushroomN();

	// delete Function
	MushroomN(const MushroomN& _Other) = delete;
	MushroomN(MushroomN&& _Other) noexcept = delete;
	MushroomN& operator=(const MushroomN& _Other) = delete;
	MushroomN& operator=(MushroomN&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void Eaten();

	void Move(float _DeltaTime);
	void MushroomGroundCheck(FVector2D _MovePos);
	void Gravity(float _DeltaTime);
	bool OnTheBlock(float _DeltaTime);

	void TurnAround(FVector2D _MovePos);

	bool GetOutOfBox(float _DeltaTime);
	void RiseUp(float _DeltaTime);

protected:

private:
	class USpriteRenderer* MushroomRenderer;
	U2DCollision* CollisionComponent;

	bool IsGround = false;

	FVector2D GravityForce = FVector2D::ZERO;
	FVector2D MoveDir = FVector2D::LEFT;
	float PosOrN = -1.0f;

};

