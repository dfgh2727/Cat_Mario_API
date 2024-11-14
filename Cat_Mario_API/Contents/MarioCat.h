#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>


enum class PlayerState
{
	Idle,
	Move,
	Jump,
	Stay,
};

class MarioCat : public AActor
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

	void SetMapImage(std::string_view _MapImageName);
	void SetColImage(std::string_view _ColImageName);

	void Gravity(float _DeltaTime);

	void PlayerGroundCheck(FVector2D _MovePos);

	void DontOverlap(float _DeltaTime);
	void BreakTheBlock(float _DeltaTime);
	bool CatOnTheBlock(float _DeltaTime);

	void DirCheck();

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
	/*void Stay(float _DeltaTime);*/

	void ChangeState(PlayerState _CurPlayerState);

	class UEngineWinImage* MapImage = nullptr;
	class UEngineWinImage* ColImage = nullptr;

	class USpriteRenderer* CatRenderer;
	U2DCollision* CollisionHead;
	U2DCollision* CollisionBody;
	U2DCollision* CollisionFoot;

	FVector2D DirVector = FVector2D::ZERO;
	float DirAcc = 1000.0f;
	float MaxSpeed = 1000.0f;
	float MinSpeed = 0.05f;
	

	std::string DirString = "Right";

	FVector2D JumpPower = FVector2D(0.0f, -500.0f);

};

