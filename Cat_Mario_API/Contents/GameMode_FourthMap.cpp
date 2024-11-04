#include "PreCompile.h"

#include "GameMode_FourthMap.h"

#include <EngineCore/Level.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "FourthMap.h"

GameMode_FourthMap::GameMode_FourthMap()
{
}

GameMode_FourthMap::~GameMode_FourthMap()
{
}

void GameMode_FourthMap::BeginPlay()
{
	{
		FourthMap* NewActor = GetWorld()->SpawnActor<FourthMap>();

	}
}

void GameMode_FourthMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_RETURN))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_FifthMap");
	}

}