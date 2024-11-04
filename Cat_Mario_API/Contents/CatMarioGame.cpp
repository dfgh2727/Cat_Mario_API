#include "PreCompile.h"
#include "CatMarioGame.h"
#include <EngineCore/EngineAPICore.h>

#include <EngineBase/EngineDirectory.h>

#include <EngineBase/EngineDebug.h>
#include <EngineBase/EngineFile.h>
#include <EngineCore/ImageManager.h>

#include "GameMode_Title.h"
#include "GameMode_FirstMap.h"
#include "GameMode_SecondMap.h"

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
		MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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

	UEngineAPICore::GetCore()->CreateLevel< GameMode_Title, AActor >("Title");
	UEngineAPICore::GetCore()->CreateLevel< GameMode_FirstMap,MarioCat >("Play_FirstMap");
	UEngineAPICore::GetCore()->CreateLevel< GameMode_SecondMap, MarioCat >("Play_SecondMap");



	UEngineAPICore::GetCore()->OpenLevel("Title");
}

void CatMarioGame::Tick()
{
	// 미사용 함수 
}

