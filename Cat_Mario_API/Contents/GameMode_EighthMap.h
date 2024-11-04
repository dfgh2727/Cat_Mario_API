#pragma once
#include <EngineCore/GameMode.h>

// Ό³Έν :
class GameMode_EighthMap : public AGameMode
{
public:
	// constrcuter destructer
	GameMode_EighthMap();
	~GameMode_EighthMap();

	// delete Function
	GameMode_EighthMap(const GameMode_EighthMap& _Other) = delete;
	GameMode_EighthMap(GameMode_EighthMap&& _Other) noexcept = delete;
	GameMode_EighthMap& operator=(const GameMode_EighthMap& _Other) = delete;
	GameMode_EighthMap& operator=(GameMode_EighthMap&& _Other) noexcept = delete;
	
	void BeginPlay();

	//void Tick(float _DeltaTime) override;

protected:

private:

};

