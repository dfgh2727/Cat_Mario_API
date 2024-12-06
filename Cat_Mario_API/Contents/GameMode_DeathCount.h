#pragma once
#include <EngineCore/GameMode.h>
#include "CountDown.h"

// Ό³Έν :
class GameMode_DeathCount : public AGameMode
{
public:
	// constrcuter destructer
	GameMode_DeathCount();
	~GameMode_DeathCount();

	// delete Function
	GameMode_DeathCount(const GameMode_DeathCount& _Other) = delete;
	GameMode_DeathCount(GameMode_DeathCount&& _Other) noexcept = delete;
	GameMode_DeathCount& operator=(const GameMode_DeathCount& _Other) = delete;
	GameMode_DeathCount& operator=(GameMode_DeathCount&& _Other) noexcept = delete;

	void BeginPlay() override;

	void LevelChangeStart() override;

	void GoToNextLevel();
	void RestartLevel();

	void Tick(float _DeltaTime) override;

	void DeathCounter();
	static int Number;

	static std::string MapNameString;

	static bool At1stMap;
	static bool At2ndMap;
	static bool At3rdMap;
	static bool At4thMap;

protected:

private:
	int Count = 0;
	CountDown* Counter;
	bool NumberIsNegative = false;
};

