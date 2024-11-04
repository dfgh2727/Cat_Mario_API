#include "PreCompile.h"

#include "GameMode_SecondMap.h"

#include <EngineCore/Level.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "SecondMap.h"

GameMode_SecondMap::GameMode_SecondMap()
{
}

GameMode_SecondMap::~GameMode_SecondMap()
{
}

void GameMode_SecondMap::BeginPlay()
{
	{
		SecondMap* NewActor = GetWorld()->SpawnActor<SecondMap>();

	}
}

