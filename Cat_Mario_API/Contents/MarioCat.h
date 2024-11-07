#pragma once
#include <EngineCore/Actor.h>

enum class PlayerState
{
	Idle,
	Move
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

	void LevelChangeStart();
	void LevelChangeEnd();

	void SetMapImage(std::string_view _MapImageName);
	void SetColImage(std::string_view _ColImageName);

protected:

private:
	float Speed = 500.0f;
	int index = 0;

	PlayerState CurPlayerState = PlayerState::Idle;

	void Idle(float _DeltaTime);
	void Move(float _DeltaTime);
	void ChangeState(PlayerState _CurPlayerState);

	class UEngineWinImage* MapImage = nullptr;
	class UEngineWinImage* ColImage = nullptr;

	class USpriteRenderer* CatRenderer;
};

