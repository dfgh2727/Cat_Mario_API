#include "PreCompile.h"
#include "GameMode_SeventhMap.h"

#include <EngineCore/Level.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "SeventhMap.h"

GameMode_SeventhMap::GameMode_SeventhMap()
{
}

GameMode_SeventhMap::~GameMode_SeventhMap()
{
}

void GameMode_SeventhMap::BeginPlay()
{
	{
		SeventhMap* NewActor = GetWorld()->SpawnActor<SeventhMap>();

	}
}

void GameMode_SeventhMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_RETURN))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_EighthMap");
	}

}
