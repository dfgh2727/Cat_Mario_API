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
	Player->SetColImage("5thMap.png");

	{
		FifthMap* NewActor = GetWorld()->SpawnActor<FifthMap>();

	}
}

void GameMode_FifthMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_RETURN))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_SixthMap");
	}

}
