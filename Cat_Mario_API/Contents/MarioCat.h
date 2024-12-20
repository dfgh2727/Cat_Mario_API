#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>
#include <EnginePlatform/EngineSound.h>

enum class PlayerState
{
	Idle,
	Move,
	Jump,
	Stay,
	Dead,
	SlipDown,
	GoToDoor,
	Clear,
	GoDown,
	WalkIn
};
 
class MarioCat : public AMapActor
{
public:
	// constrcuter destructer
	MarioCat();
	~MarioCat();

	// delete Function
	MarioCat(const MarioCat& _Other) = delete;
	MarioCat(MarioCat&& _Other) noexcept = delete;
	MarioCat& operator=(const MarioCat& _Other) = delete;
	MarioCat& operator=(MarioCat&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void MainCamera();


	void LevelChangeStart();
	void LevelChangeEnd();

	void Gravity(float _DeltaTime);

	void PlayerGroundCheck(FVector2D _MovePos);

	void DontOverlap(float _DeltaTime);
	void HitTheBlock(float _DeltaTime);
	bool CatOnTheBlock(float _DeltaTime);

	void CatIsKilled(float _DeltaTime);
	void YouDied(float _DeltaTime);
	/*void IsCatAlive(float _DeltaTime);*/

	void DirCheck();

	void Bounce(float _DeltaTime);
	void SueprBounce(float _DeltaTime);

	void PipeCheck();
	void PipeMotion(float _DeltaTime);
	void CatInThePipe();

	void RightBeforeDeath(float _DeltaTime);
	void TurnOffTheSwitch();
	void DeathCheck();

	/*static bool TouchFlag;*/

	static bool IsCatDead;
	static bool IsCatKilled;
	
	static FVector2D StartPos;

	bool StaffTouched = false;
	bool StaffBlockTouched = false;

	void StartEndMotion();
	void EndMotion1(float _DeltaTime);
	void EndMotion2(float _DeltaTime);
	void YouCleared(float _DeltaTime);

	bool OverTheStaff = false;
	bool AtTheDoor = false;
	bool Cleared = false;

	bool OnThePipe = false;
	bool InThePipe = false;

	PlayerState GetPlayerState() 
	{
		return CurPlayerState;
	}

	FVector2D GetGravityForce()
	{
		return GravityForce;
	}

	FVector2D GetJumpPower()
	{
		return JumpPower;
	}

	void Hide();
	void Appear();

	void ChangeState(PlayerState _CurPlayerState);
	void TryToWalkIn();
	void WalkingIn(float _DeltaTime);
	bool CatWalkIn = false;
	bool ItsTunnel = false;

	void LaunchTheCat(float _DeltaTime);

protected:

private:
	int index = 0;

	int IsGround = false;
	FVector2D GravityForce = FVector2D::ZERO;
	FVector2D FrictionCo = FVector2D::ZERO;
	FVector2D CatPos = FVector2D::ZERO;

	PlayerState CurPlayerState = PlayerState::Idle;

	void Idle(float _DeltaTime);
	void Move(float _DeltaTime);
	void Jump(float _DeltaTime);


	class USpriteRenderer* CatRenderer;
	U2DCollision* CollisionHead;
	U2DCollision* CollisionBody;
	U2DCollision* CollisionFoot;

	FVector2D DirVector = FVector2D::ZERO;
	float DirAcc = 1000.0f;
	float MaxSpeed = 800.0f;
	float MinSpeed = 0.05f;
	
	std::string DirString = "Right";

	FVector2D JumpPower = FVector2D(0.0f, -1000.0f);
	FVector2D PrevPos = FVector2D::ZERO;
	bool DeathMotionSwitch = true;
	USoundPlayer BGMPlayer;

};

