#pragma once
#include <EngineCore/GameMode.h>

// Ό³Έν :
class GameMode_SeventhMap : public AGameMode
{
public:
	// constrcuter destructer
	GameMode_SeventhMap();
	~GameMode_SeventhMap();

	// delete Function
	GameMode_SeventhMap(const GameMode_SeventhMap& _Other) = delete;
	GameMode_SeventhMap(GameMode_SeventhMap&& _Other) noexcept = delete;
	GameMode_SeventhMap& operator=(const GameMode_SeventhMap& _Other) = delete;
	GameMode_SeventhMap& operator=(GameMode_SeventhMap&& _Other) noexcept = delete;

	void BeginPlay() override;

	void Tick(float _DeltaTime) override;

protected:

private:

};

