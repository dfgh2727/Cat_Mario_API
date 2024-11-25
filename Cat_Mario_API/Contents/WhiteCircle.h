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

	void Move(float _DeltaTime);
	void MonsterGroundCheck(FVector2D _MovePos);
	void Gravity(float _DeltaTime);
	bool OnTheBlock(float _DeltaTime);

	void IsKilled(float _DeltaTime);
	void TurnAround(FVector2D _MovePos);
	
	bool GetOutOfBox(float _DeltaTime);
	void RiseUp(float _DeltaTime);

protected:

private:
	class USpriteRenderer* MonsterRenderer;
	U2DCollision* MonsterBody;
	U2DCollision* BouncyBody;
	bool IsGround = false;

	FVector2D GravityForce = FVector2D::ZERO;
	FVector2D MoveDir = FVector2D::LEFT;
	float PosOrN = -1.0f;

	bool MonsterIsKilled = false;
};
