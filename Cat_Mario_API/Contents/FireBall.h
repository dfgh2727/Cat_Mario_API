#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>
#include <EngineBase/EngineRandom.h>

// Ό³Έν :
class FireBall : public AActor
{
public:
	// constrcuter destructer
	FireBall();
	~FireBall();

	// delete Function
	FireBall(const FireBall& _Other) = delete;
	FireBall(FireBall&& _Other) noexcept = delete;
	FireBall& operator=(const FireBall& _Other) = delete;
	FireBall& operator=(FireBall&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Gravity(float _DeltaTime);
	static UEngineRandom Random;


protected:

private:
	class USpriteRenderer* FBRenderer;
	FVector2D MoveVec = FVector2D::ZERO;
	FVector2D GravityForce = FVector2D::ZERO;
	U2DCollision* CollisionComponent;
	FVector2D FBVelocity;
};

