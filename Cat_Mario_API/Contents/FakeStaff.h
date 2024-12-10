#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class FakeStaff : public AMapActor
{
public:
	// constrcuter destructer
	FakeStaff();
	~FakeStaff();

	// delete Function
	FakeStaff(const FakeStaff& _Other) = delete;
	FakeStaff(FakeStaff&& _Other) noexcept = delete;
	FakeStaff& operator=(const FakeStaff& _Other) = delete;
	FakeStaff& operator=(FakeStaff&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Move(float _DeltaTime);
	void MonsterGroundCheck(FVector2D _MovePos);
	void Gravity(float _DeltaTime);
	//bool OnTheBlock(float _DeltaTime);

	void TurnAround(FVector2D _MovePos);
	void SetDirection();

	bool GoRight = false;
	bool GoLeft = false;
	bool MoveSwitch = false;

protected:

private:
	class USpriteRenderer* StaffRenderer;
	U2DCollision* CollisionComponent1;
	U2DCollision* CollisionComponent2;

	bool IsGround = false;

	FVector2D GravityForce = FVector2D::ZERO;
	FVector2D MoveDir = FVector2D::LEFT;
	float PosOrN = -1.0f;
};

