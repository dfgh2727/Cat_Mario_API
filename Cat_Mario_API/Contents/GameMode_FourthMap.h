#pragma once
#include <EngineCore/GameMode.h>


// Ό³Έν :
class GameMode_FourthMap : public AGameMode
{
public:
	// constrcuter destructer
	GameMode_FourthMap();
	~GameMode_FourthMap();

	// delete Function
	GameMode_FourthMap(const GameMode_FourthMap& _Other) = delete;
	GameMode_FourthMap(GameMode_FourthMap&& _Other) noexcept = delete;
	GameMode_FourthMap& operator=(const GameMode_FourthMap& _Other) = delete;
	GameMode_FourthMap& operator=(GameMode_FourthMap&& _Other) noexcept = delete;

	void BeginPlay() override;

	void Tick(float _DeltaTime) override;

protected:

private:

};

