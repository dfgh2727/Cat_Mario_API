#include "PreCompile.h"

#include "GameMode_ThirdMap.h"

#include <EngineCore/Level.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "ThirdMap.h"

GameMode_ThirdMap::GameMode_ThirdMap()
{
}

GameMode_ThirdMap::~GameMode_ThirdMap()
{
}

void GameMode_ThirdMap::BeginPlay()
{
	{
		ThirdMap* NewActor = GetWorld()->SpawnActor<ThirdMap>();

	}
}

void GameMode_ThirdMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_RETURN))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_FourthMap");
	}

}

