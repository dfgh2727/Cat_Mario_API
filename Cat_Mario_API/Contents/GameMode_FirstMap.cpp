#include "PreCompile.h"
#include "GameMode_FirstMap.h"

#include <EngineCore/Level.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "FirstMap.h"
#include "MarioCat.h"


GameMode_FirstMap::GameMode_FirstMap()
{
}

GameMode_FirstMap::~GameMode_FirstMap()
{
}

void GameMode_FirstMap::BeginPlay()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	Player->SetColImage("1stMap.png");

	{
	FirstMap* NewActor = GetWorld()->SpawnActor<FirstMap>();

	}
}

void GameMode_FirstMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_RETURN))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_SecondMap");
	}

}

