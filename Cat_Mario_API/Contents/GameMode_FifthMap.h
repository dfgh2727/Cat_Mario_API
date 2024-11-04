#pragma once
#include <EngineCore/GameMode.h>


// Ό³Έν :
class GameMode_FifthMap : public AGameMode
{
public:
	// constrcuter destructer
	GameMode_FifthMap();
	~GameMode_FifthMap();

	// delete Function
	GameMode_FifthMap(const GameMode_FifthMap& _Other) = delete;
	GameMode_FifthMap(GameMode_FifthMap&& _Other) noexcept = delete;
	GameMode_FifthMap& operator=(const GameMode_FifthMap& _Other) = delete;
	GameMode_FifthMap& operator=(GameMode_FifthMap&& _Other) noexcept = delete;

	void BeginPlay() override;

	void Tick(float _DeltaTime) override;

protected:

private:

};

