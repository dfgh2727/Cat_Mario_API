#pragma once
#include <EngineCore/GameMode.h>
#include <EnginePlatform/EngineSound.h>

// Ό³Έν :
class GameMode_SecondMap : public AGameMode
{
public:
	// constrcuter destructer
	GameMode_SecondMap();
	~GameMode_SecondMap();

	// delete Function
	GameMode_SecondMap(const GameMode_SecondMap& _Other) = delete;
	GameMode_SecondMap(GameMode_SecondMap&& _Other) noexcept = delete;
	GameMode_SecondMap& operator=(const GameMode_SecondMap& _Other) = delete;
	GameMode_SecondMap& operator=(GameMode_SecondMap&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelChangeStart() override;
	void ReStart(float _DeltaTime);
	void GoToDeathCount();

	void SealSwitch();
	void LaunchTheSeal();
	void Clear();
	void OpenNextLevel();
	void StopTheMusic();

protected:

private:
	class UpSeal* Seal;

	bool SwitchLever = false;

	bool SoundSwtich = true;
	USoundPlayer BGMPlayer;
	USoundPlayer DeathSoundPlayer;
};

