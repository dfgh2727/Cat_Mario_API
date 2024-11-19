#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class WhiteCircle : public AMapActor
{
public:
	// constrcuter destructer
	WhiteCircle();
	~WhiteCircle();

	// delete Function
	WhiteCircle(const WhiteCircle& _Other) = delete;
	WhiteCircle(WhiteCircle&& _Other) noexcept = delete;
	WhiteCircle& operator=(const WhiteCircle& _Other) = delete;
	WhiteCircle& operator=(WhiteCircle&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void MonsterGroundCheck(FVector2D _MovePos);
	void Gravity(float _DeltaTime);
	bool OnTheBlock(float _DeltaTime);

	void IsKilled(float _DeltaTime);
	void TurnAround(FVector2D _MovePos);

protected:

private:
	class USpriteRenderer* MonsterRenderer;
	U2DCollision* MonsterBody;
	bool IsGround = false;

	void Move(float _DeltaTime);
	
	FVector2D GravityForce = FVector2D::ZERO;
	FVector2D MoveDir = FVector2D::LEFT;
	float PosOrN = -1.0f;
};
