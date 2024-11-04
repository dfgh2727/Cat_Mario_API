#include "PreCompile.h"
#include "CatMarioGame.h"
#include <EngineCore/EngineAPICore.h>

#include <EngineBase/EngineDirectory.h>

#include <EngineBase/EngineDebug.h>
#include <EngineBase/EngineFile.h>
#include <EngineCore/ImageManager.h>

#include "GameMode_FirstMap.h"
#include "MarioCat.h"


CatMarioGame::CatMarioGame()
{
}

CatMarioGame::~CatMarioGame()
{
}

void CatMarioGame::BeginPlay()
{

	UEngineDirectory Dir;

	if (false == Dir.MoveParentToDirectory("Resources"))
	{
		MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
		return;
	}

	std::vector<UEngineFile> ImageFiles = Dir.GetAllFile();

	for (size_t i = 0; i < ImageFiles.size(); i++)
	{
		std::string FilePath = ImageFiles[i].GetPathToString();
		UImageManager::GetInst().Load(FilePath);
	}


	UImageManager::GetInst().CuttingSprite("CMPlayer.png", { 128, 128 });


	UEngineAPICore::GetCore()->GetMainWindow().SetWindowTitle("Cat Mario Game");

	UEngineAPICore::GetCore()->GetMainWindow().SetWindowPosAndScale({ 0, 0 }, { 1260, 630 });

	UEngineAPICore::GetCore()->CreateLevel< GameMode_FirstMap,MarioCat >("FirstMapPlay");
	UEngineAPICore::GetCore()->CreateLevel< GameMode_FirstMap, AActor >("Title");


	UEngineAPICore::GetCore()->OpenLevel("TestPlay");
}

void CatMarioGame::Tick()
{
	// �̻�� �Լ� 
}

