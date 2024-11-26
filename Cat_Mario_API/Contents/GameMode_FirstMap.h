#pragma once
#include <EngineCore/GameMode.h>

// Ό³Έν :
class GameMode_FirstMap : public AGameMode
{
public:
	// constrcuter destructer
	GameMode_FirstMap();
	~GameMode_FirstMap();

	// delete Function
	GameMode_FirstMap(const GameMode_FirstMap& _Other) = delete;
	GameMode_FirstMap(GameMode_FirstMap&& _Other) noexcept = delete;
	GameMode_FirstMap& operator=(const GameMode_FirstMap& _Other) = delete;
	GameMode_FirstMap& operator=(GameMode_FirstMap&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void ReStart(float _DeltaTime);
	/*void IsFlagGone();*/

	void LevelChangeStart() override;

	void SealSwtich();

	void SealGoUp();
	void SealGoDown();

	void OverTheStaff();
	void AtTheDoor();
	void Clear();

	void GoToDeathCount();

protected:

private:
	//class QuestionMark* QMark = nullptr;
	//class Flag* MiddlePointFlag = nullptr;
	class UpSeal* Seal1;
	class DownSeal* Seal2;
	DownSeal* Seal3;
	bool Seal1Lever = false;
	bool Seal2Lever = false;
	bool Seal3Lever = false;
};

