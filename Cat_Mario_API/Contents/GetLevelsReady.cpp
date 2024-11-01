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

void GetLevelsReady::MakeActors()
{
	{
	MakeMap* NewActor = GetWorld()->SpawnActor<MakeMap>();
	}
}

