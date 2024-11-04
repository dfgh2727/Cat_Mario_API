#pragma once
#include <EngineCore/GameMode.h>


// Ό³Έν :
class GameMode_SixthMap : public AGameMode
{
public:
	// constrcuter destructer
	GameMode_SixthMap();
	~GameMode_SixthMap();

	// delete Function
	GameMode_SixthMap(const GameMode_SixthMap& _Other) = delete;
	GameMode_SixthMap(GameMode_SixthMap&& _Other) noexcept = delete;
	GameMode_SixthMap& operator=(const GameMode_SixthMap& _Other) = delete;
	GameMode_SixthMap& operator=(GameMode_SixthMap&& _Other) noexcept = delete;

	void BeginPlay() override;

	void Tick(float _DeltaTime) override;

protected:

private:

};

