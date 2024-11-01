#pragma once
#include <EngineCore/GameMode.h>

// Ό³Έν :
class GetLevelsReady : public AGameMode
{
public:
	// constrcuter destructer
	GetLevelsReady();
	~GetLevelsReady();

	// delete Function
	GetLevelsReady(const GetLevelsReady& _Other) = delete;
	GetLevelsReady(GetLevelsReady&& _Other) noexcept = delete;
	GetLevelsReady& operator=(const GetLevelsReady& _Other) = delete;
	GetLevelsReady& operator=(GetLevelsReady&& _Other) noexcept = delete;

	void MakeActors();

protected:

private:

};

