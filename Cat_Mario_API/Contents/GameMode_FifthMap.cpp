#include "PreCompile.h"
#include "GameMode_FifthMap.h"

#include <EngineCore/Level.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "FifthMap.h"
#include "MarioCat.h"


GameMode_FifthMap::GameMode_FifthMap()
{
}

GameMode_FifthMap::~GameMode_FifthMap()
{
}

void GameMode_FifthMap::BeginPlay()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	Player->SetMapImage("5thMap.png");
	Player->SetColImage("5thColMap.png");


	{
		FifthMap* NewActor = GetWorld()->SpawnActor<FifthMap>();

	}
}

void GameMode_FifthMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_SixthMap");
	}

}
