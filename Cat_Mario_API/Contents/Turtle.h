#pragma once
#include "WhiteCircle.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class Turtle : public WhiteCircle
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

