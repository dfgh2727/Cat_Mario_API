#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class TurtleShell : public AMapActor
{
public:
	// constrcuter destructer
	TurtleShell();
	~TurtleShell();

	// delete Function
	TurtleShell(const TurtleShell& _Other) = delete;
	TurtleShell(TurtleShell&& _Other) noexcept = delete;
	TurtleShell& operator=(const TurtleShell& _Other) = delete;
	TurtleShell& operator=(TurtleShell&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Move(float _DeltaTime);

	void MonsterGroundCheck(FVector2D _MovePos);
	void Gravity(float _DeltaTime);
	bool OnTheBlock(float _DeltaTime);
	void TurnAround(FVector2D _MovePos);
	
	class USpriteRenderer* MonsterRenderer;
protected:

private:
	U2DCollision* MonsterBody;
	U2DCollision* LeftBody;
	U2DCollision* RightBody;
	U2DCollision* BouncyBody;
	bool IsGround = false;

	FVector2D GravityForce = FVector2D::ZERO;
	FVector2D MoveDir = FVector2D::LEFT;
	float PosOrN = -1.0f;
};

