#include "PreCompile.h"

#include "GameMode_SecondMap.h"

#include <EngineCore/Level.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "SecondMap.h"
#include "MarioCat.h"

GameMode_SecondMap::GameMode_SecondMap()
{
}

GameMode_SecondMap::~GameMode_SecondMap()
{
}

void GameMode_SecondMap::BeginPlay()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	Player->SetColImage("2ndMap.png");

	{
		SecondMap* NewActor = GetWorld()->SpawnActor<SecondMap>();

	}
}

void GameMode_SecondMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_RETURN))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_ThirdMap");
	}

}
