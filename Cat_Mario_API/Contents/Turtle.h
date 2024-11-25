#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class Turtle : public AMapActor
{
public:
	// constrcuter destructer
	Turtle();
	~Turtle();

	// delete Function
	Turtle(const Turtle& _Other) = delete;
	Turtle(Turtle&& _Other) noexcept = delete;
	Turtle& operator=(const Turtle& _Other) = delete;
	Turtle& operator=(Turtle&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Move(float _DeltaTime);
	void MonsterGroundCheck(FVector2D _MovePos);
	void Gravity(float _DeltaTime);
	bool OnTheBlock(float _DeltaTime);
	void TurnAround(FVector2D _MovePos);

	void IsKilled(float _DeltaTime);
	void SpawnShell();

protected:

private:
	class USpriteRenderer* MonsterRenderer;
	U2DCollision* MonsterBody;
	U2DCollision* BouncyBody;
	bool IsGround = false;

	float PosOrN = -1.0f;
	FVector2D GravityForce = FVector2D::ZERO;
	FVector2D MoveDir = FVector2D::LEFT;

	bool MonsterIsKilled = false;
};

