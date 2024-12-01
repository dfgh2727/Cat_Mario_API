#include "PreCompile.h"
#include "CatMarioGame.h"
#include <EngineCore/EngineAPICore.h>

#include <EngineBase/EngineDirectory.h>

#include <EngineBase/EngineDebug.h>
#include <EngineBase/EngineFile.h>
#include <EngineCore/ImageManager.h>
#include <EnginePlatform/EngineSound.h>

#include "GameMode_Title.h"
#include "GameMode_FirstMap.h"
#include "GameMode_SecondMap.h"
#include "GameMode_ThirdMap.h"
#include "GameMode_FourthMap.h"
#include "GameMode_FifthMap.h"
#include "GameMode_SixthMap.h"
#include "GameMode_SeventhMap.h"
#include "GameMode_EighthMap.h"
#include "GameMode_DeathCount.h"
#include "GameMode_TheEnd.h"



#include "MarioCat.h"


CatMarioGame::CatMarioGame()
{
}

CatMarioGame::~CatMarioGame()
{
}

void CatMarioGame::BeginPlay()
{
	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("Resources"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}

		Dir.Append("Image");
		std::vector<UEngineFile> ImageFiles = Dir.GetAllFile();
		for (size_t i = 0; i < ImageFiles.size(); i++)
		{
			std::string FilePath = ImageFiles[i].GetPathToString();
			UImageManager::GetInst().Load(FilePath);
		}
	}

	// 사운드 로드
	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("Resources"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}

		Dir.Append("Sound");
		std::vector<UEngineFile> ImageFiles = Dir.GetAllFile();
		for (size_t i = 0; i < ImageFiles.size(); i++)
		{
			std::string FilePath = ImageFiles[i].GetPathToString();
			UEngineSound::Load(FilePath);
		}
	}

	UImageManager::GetInst().CuttingSprite("CMPlayer_Right.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("CMPlayer_Left.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("CMnum.png", { 64, 128 });
	UImageManager::GetInst().CuttingSprite("CMmon_Right.png", { 128, 128 });
	UImageManager::GetInst().CuttingSprite("CMmon_Left.png", { 128, 128 });

	UEngineAPICore::GetCore()->GetMainWindow().SetWindowTitle("Cat Mario Game");

	UEngineAPICore::GetCore()->GetMainWindow().SetWindowPosAndScale({ 0, 0 }, { 960, 840 });

	UEngineAPICore::GetCore()->CreateLevel< GameMode_Title, AActor >("Title");
	UEngineAPICore::GetCore()->CreateLevel< GameMode_FirstMap, MarioCat >("Play_FirstMap");
	UEngineAPICore::GetCore()->CreateLevel< GameMode_SecondMap, MarioCat >("Play_SecondMap");
	UEngineAPICore::GetCore()->CreateLevel< GameMode_ThirdMap, MarioCat >("Play_ThirdMap");
	UEngineAPICore::GetCore()->CreateLevel< GameMode_FourthMap, MarioCat >("Play_FourthMap");
	UEngineAPICore::GetCore()->CreateLevel< GameMode_FifthMap, MarioCat >("Play_FifthMap");
	UEngineAPICore::GetCore()->CreateLevel< GameMode_SixthMap, MarioCat >("Play_SixthMap");
	UEngineAPICore::GetCore()->CreateLevel< GameMode_SeventhMap, MarioCat >("Play_SeventhMap");
	UEngineAPICore::GetCore()->CreateLevel< GameMode_EighthMap, MarioCat >("Play_EighthMap");
	UEngineAPICore::GetCore()->CreateLevel< GameMode_TheEnd, AActor >("TheEnd");

	UEngineAPICore::GetCore()->CreateLevel< GameMode_DeathCount, AActor >("DeathCount");

	UEngineAPICore::GetCore()->OpenLevel("Title");
}

void CatMarioGame::Tick()
{
	// 미사용 함수 
}


