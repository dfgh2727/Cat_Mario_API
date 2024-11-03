#include "PreCompile.h"
#include "GetLevelsReady.h"

#include <EngineCore/Level.h>
#include "MakeMap.h"


GetLevelsReady::GetLevelsReady()
{
}

GetLevelsReady::~GetLevelsReady()
{
}

void GetLevelsReady::BeginPlay()
{
	{
	MakeMap* NewActor = GetWorld()->SpawnActor<MakeMap>();

	int a = 0;
	}
}

