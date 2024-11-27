#pragma once
#include <EngineCore/GameMode.h>


// Ό³Έν :
class GameMode_ThirdMap : public AGameMode
{
public:
	// constrcuter destructer
	GameMode_ThirdMap();
	~GameMode_ThirdMap();

	// delete Function
	GameMode_ThirdMap(const GameMode_ThirdMap& _Other) = delete;
	GameMode_ThirdMap(GameMode_ThirdMap&& _Other) noexcept = delete;
	GameMode_ThirdMap& operator=(const GameMode_ThirdMap& _Other) = delete;
	GameMode_ThirdMap& operator=(GameMode_ThirdMap&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelChangeStart() override;
	void ReStart(float _DeltaTime);
	void GoToDeathCount();

	void Clear();
	void OpenNextLevel();
protected:

private:

};

