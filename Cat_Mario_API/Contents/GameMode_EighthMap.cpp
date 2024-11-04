#include "PreCompile.h"
#include "GameMode_EighthMap.h"

#include <EngineCore/Level.h>
#include "EighthMap.h"

GameMode_EighthMap::GameMode_EighthMap()
{
}

GameMode_EighthMap::~GameMode_EighthMap()
{
}

void GameMode_EighthMap::BeginPlay()
{
	{
		EighthMap* NewActor = GetWorld()->SpawnActor<EighthMap>();

	}
}

