#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// ���� :
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

	void MonsterGroundCheck(FVector2D _MovePos);
	void Gravity(float _DeltaTime);
	bool OnTheBlock(float _DeltaTime);
	void TurnAround(FVector2D _MovePos);
protected:

private:
	class USpriteRenderer* MonsterRenderer;
	U2DCollision* MonsterBody;
	U2DCollision* BouncyBody;
	bool IsGround = false;

	FVector2D GravityForce = FVector2D::ZERO;
	FVector2D MoveDir = FVector2D::LEFT;
	float PosOrN = -1.0f;
};

