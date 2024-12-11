#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class Bear : public AMapActor
{
public:
	// constrcuter destructer
	Bear();
	~Bear();

	// delete Function
	Bear(const Bear& _Other) = delete;
	Bear(Bear&& _Other) noexcept = delete;
	Bear& operator=(const Bear& _Other) = delete;
	Bear& operator=(Bear&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Move(float _DeltaTime);
	void MonsterGroundCheck(FVector2D _MovePos);
	void Gravity(float _DeltaTime);

	void TurnAround(FVector2D _MovePos);
	void JumpUp(float _DeltaTime);

protected:

private:
	class USpriteRenderer* MonsterRenderer;
	U2DCollision* MonsterBody;

	bool IsGround = false;

	FVector2D GravityForce = FVector2D::ZERO;
	FVector2D MoveDir = FVector2D::LEFT;
	float PosOrN = -1.0f;

	FVector2D JumpPower = FVector2D( 0.0f, -700.0f);

	bool DoItOnce = true;
	float Timer = 0.0;
};
