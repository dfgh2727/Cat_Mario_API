#include "PreCompile.h"
#include "GameMode_SixthMap.h"

#include <EngineCore/Level.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "SixthMap.h"

GameMode_SixthMap::GameMode_SixthMap()
{
}

GameMode_SixthMap::~GameMode_SixthMap()
{
}

void GameMode_SixthMap::BeginPlay()
{
	{
		SixthMap* NewActor = GetWorld()->SpawnActor<SixthMap>();

	}
}

void GameMode_SixthMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_RETURN))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_SeventhMap");
	}

}
