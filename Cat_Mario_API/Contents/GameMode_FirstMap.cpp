#include "PreCompile.h"
#include "GameMode_FirstMap.h"

#include <EngineCore/Level.h>
#include "FirstMap.h"


GameMode_FirstMap::GameMode_FirstMap()
{
}

GameMode_FirstMap::~GameMode_FirstMap()
{
}

void GameMode_FirstMap::BeginPlay()
{
	{
	FirstMap* NewActor = GetWorld()->SpawnActor<FirstMap>();

	}
}

