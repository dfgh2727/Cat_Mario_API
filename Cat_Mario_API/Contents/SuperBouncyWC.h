#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class SuperBouncyWC : public AMapActor
{
public:
	// constrcuter destructer
	SuperBouncyWC();
	~SuperBouncyWC();

	// delete Function
	SuperBouncyWC(const SuperBouncyWC& _Other) = delete;
	SuperBouncyWC(SuperBouncyWC&& _Other) noexcept = delete;
	SuperBouncyWC& operator=(const SuperBouncyWC& _Other) = delete;
	SuperBouncyWC& operator=(SuperBouncyWC&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void MonsterGroundCheck(FVector2D _MovePos);
	void Gravity(float _DeltaTime);
	void TurnAround(FVector2D _MovePos);

protected:

private:
	class USpriteRenderer* MonsterRenderer;
	U2DCollision* MonsterBody;
	U2DCollision* SuperBouncyBody;
	bool IsGround = false;

	void Move(float _DeltaTime);

	FVector2D GravityForce = FVector2D::ZERO;
	FVector2D MoveDir = FVector2D::LEFT;
	float PosOrN = -1.0f;

	bool MonsterIsKilled = false;
};

