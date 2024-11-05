#include "PreCompile.h"
#include "GameMode_EighthMap.h"

#include <EngineCore/Level.h>
#include "EighthMap.h"
#include "MarioCat.h"

GameMode_EighthMap::GameMode_EighthMap()
{
}

GameMode_EighthMap::~GameMode_EighthMap()
{
}

void GameMode_EighthMap::BeginPlay()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	Player->SetMapImage("8thMap.png");

	{
		EighthMap* NewActor = GetWorld()->SpawnActor<EighthMap>();

	}
}

