#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class WhiteCircle : public AActor
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

protected:

private:

	void Move(float _DeltaTime);
	FVector2D GravityForce = FVector2D::ZERO;
	bool IsGround = false;

	class USpriteRenderer* MonsterRenderer;

	U2DCollision* MonsterBody;
	class UEngineWinImage* ColImage = nullptr;

};
