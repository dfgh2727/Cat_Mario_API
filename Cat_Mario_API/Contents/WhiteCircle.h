#pragma once
#include <EngineCore/Actor.h>
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

	void PlayerGroundCheck(FVector2D _MovePos);
	void Gravity(float _DeltaTime);

protected:

private:

	class UEngineWinImage* ColImage = nullptr;

	class USpriteRenderer* MonsterRenderer;
	bool IsGround = false;

	FVector2D GravityForce = FVector2D::ZERO;

};
