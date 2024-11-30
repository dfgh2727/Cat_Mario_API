#pragma once
#include <EngineCore/GameMode.h>
#include <EnginePlatform/EngineSound.h>

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

	void FSSwtich();
	void FlyingStickAppears();


	void OverTheStaff();
	void AtTheDoor();
	void Clear();

	void GoToDeathCount();
	void StopTheMusic();

	void CatIsInThePipe(float _DeltaTime);
	void CatIsUnderTheBlock();
	void MonsterSwitch1();
	void MonsterSwitch2();
	void MonsterShowUp1();
	void MonsterShowUp2();



protected:

private:
	//class QuestionMark* QMark = nullptr;
	//class Flag* MiddlePointFlag = nullptr;
	class UpSeal* Seal1;
	class DownSeal* Seal2;
	DownSeal* Seal3;

	class FirstMapP2* P2;
	class FDBlock1* FDB;
	bool Seal1Lever = false;
	bool Seal2Lever = false;
	bool Seal3Lever = false;

	bool FSLever = false;

	bool MonsterLever1 = false;
	bool MonsterLever2 = false;
	bool DoItOnce1 = true;
	bool DoItOnce2 = true;
	bool DoItOnce3 = true;

	float Time = 0.0f;
	USoundPlayer BGMPlayerBase;
};

