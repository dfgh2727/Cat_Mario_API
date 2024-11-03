#pragma once
#include <EngineCore/EngineAPICore.h>
#include <EnginePlatform/EngineWindow.h>

// Ό³Έν :
class CatMarioGame : public UContentsCore
{
public:
	// constrcuter destructer
	CatMarioGame();
	~CatMarioGame();

	// delete Function
	CatMarioGame(const CatMarioGame& _Other) = delete;
	CatMarioGame(CatMarioGame&& _Other) noexcept = delete;
	CatMarioGame& operator=(const CatMarioGame& _Other) = delete;
	CatMarioGame& operator=(CatMarioGame&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick() override;
 

private:
	ULevel* TitleLevel;
};

