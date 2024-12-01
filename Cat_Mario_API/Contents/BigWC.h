#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class BigWC : public AMapActor
{
public:
	// constrcuter destructer
	BigWC();
	~BigWC();

	// delete Function
	BigWC(const BigWC& _Other) = delete;
	BigWC(BigWC&& _Other) noexcept = delete;
	BigWC& operator=(const BigWC& _Other) = delete;
	BigWC& operator=(BigWC&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Move(float _DeltaTime);
	void MonsterGroundCheck(FVector2D _MovePos);
	void Gravity(float _DeltaTime);
	bool OnTheBlock(float _DeltaTime);

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
