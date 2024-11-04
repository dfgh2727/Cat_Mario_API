#pragma once
#include <EngineCore/GameMode.h>

// Ό³Έν :
class GameMode_Title: public AGameMode
{
public:
	// constrcuter destructer
	GameMode_Title();
	~GameMode_Title();

	// delete Function
	GameMode_Title(const GameMode_Title& _Other) = delete;
	GameMode_Title(GameMode_Title&& _Other) noexcept = delete;
	GameMode_Title& operator=(const GameMode_Title& _Other) = delete;
	GameMode_Title& operator=(GameMode_Title&& _Other) noexcept = delete;

	void BeginPlay() override;

	void Tick(float _DeltaTime) override;


protected:

private:

};

