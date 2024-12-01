#pragma once
#include <EngineCore/GameMode.h>


// Ό³Έν :
class GameMode_TheEnd : public AGameMode
{
public:
	// constrcuter destructer
	GameMode_TheEnd();
	~GameMode_TheEnd();

	// delete Function
	GameMode_TheEnd(const GameMode_TheEnd& _Other) = delete;
	GameMode_TheEnd(GameMode_TheEnd&& _Other) noexcept = delete;
	GameMode_TheEnd& operator=(const GameMode_TheEnd& _Other) = delete;
	GameMode_TheEnd& operator=(GameMode_TheEnd&& _Other) noexcept = delete;

	void BeginPlay() override;

	void Tick(float _DeltaTime) override;

protected:

private:

};

