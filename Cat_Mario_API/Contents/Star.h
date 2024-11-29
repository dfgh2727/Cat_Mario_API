#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class Star : public AMapActor
{
public:
	// constrcuter destructer
	Star();
	~Star();

	// delete Function
	Star(const Star& _Other) = delete;
	Star(Star&& _Other) noexcept = delete;
	Star& operator=(const Star& _Other) = delete;
	Star& operator=(Star&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Move(float _DeltaTime);
	void MonsterGroundCheck(FVector2D _MovePos);
	void Gravity(float _DeltaTime);
	bool OnTheBlock(float _DeltaTime);

	void TurnAround(FVector2D _MovePos);

	bool GetOutOfBox(float _DeltaTime);
	void RiseUp(float _DeltaTime);
	
protected:

private:
	class USpriteRenderer* MonsterRenderer;
	U2DCollision* MonsterBody;
	bool IsGround = false;

	FVector2D JumpPower = FVector2D(0.0f, -750.0f);

	FVector2D GravityForce = FVector2D::ZERO;
	FVector2D MoveDir = FVector2D::LEFT;
	float PosOrN = -1.0f;
};

