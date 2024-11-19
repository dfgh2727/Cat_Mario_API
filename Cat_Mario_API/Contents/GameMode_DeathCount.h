#pragma once
#include <EngineCore/GameMode.h>

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

	void Tick(float _DeltaTime) override;

	void DeathCounter();

	int Count;

protected:

private:

};

