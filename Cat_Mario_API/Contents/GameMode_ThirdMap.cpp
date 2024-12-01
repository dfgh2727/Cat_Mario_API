#include "PreCompile.h"
#include "GameMode_ThirdMap.h"

#include <EngineCore/Level.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>
#include "GameMode_DeathCount.h"

#include "ThirdMap.h"
#include "MarioCat.h"

#include "FBPipe.h"
#include "FDBlock3.h"

GameMode_ThirdMap::GameMode_ThirdMap()
{

}

GameMode_ThirdMap::~GameMode_ThirdMap()
{
}

void GameMode_ThirdMap::BeginPlay()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	Player->SetMapImage("3rdMap.png");
	Player->SetColImage("3rdColMap.png");

	{
		ThirdMap* NewActor = GetWorld()->SpawnActor<ThirdMap>();
	}

	{
		FDBlock3* NewActor = GetWorld()->SpawnActor<FDBlock3>();
		NewActor->SetActorLocation({ 146, 786 });
	}
	{
		FDBlock3* NewActor = GetWorld()->SpawnActor<FDBlock3>();
		NewActor->SetActorLocation({ 1421, 786 });
	}
	{
		FBPipe* NewActor = GetWorld()->SpawnActor<FBPipe>();
		NewActor->SetActorLocation({ 5975, 619 });
	}
}

void GameMode_ThirdMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	ReStart(_DeltaTime);
	Clear();

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_FourthMap");
	}

	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();

	if (true == UEngineInput::GetInst().IsDown(VK_F3))
	{
		Player->SetActorLocation({ 5700, 700 });
	}

}

void GameMode_ThirdMap::LevelChangeStart()
{
	Super::LevelChangeStart();

	static bool Check = false;

	if (Check == false)
	{
		MarioCat::StartPos = { 148, 10 };
		Check = true;
	}
}

void GameMode_ThirdMap::ReStart(float _DeltaTime)
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();

	if (true == Player->IsCatDead)
	{
		--GameMode_DeathCount::Number;
		GameMode_DeathCount::At3rdMap = true;

		GoToDeathCount();
	}
}

void GameMode_ThirdMap::GoToDeathCount()
{
	UEngineAPICore::GetCore()->OpenLevel("DeathCount");
}

void GameMode_ThirdMap::Clear()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();

	if (Player->InThePipe == true)
	{
		GameMode_DeathCount::MapNameString = "Fourth";
		GameMode_DeathCount::At3rdMap = false;

		MarioCat::StartPos = { 148, 10 };
		TimeEventer.PushEvent(0.5f, std::bind(&GameMode_ThirdMap::OpenNextLevel, this));
	}
}

void GameMode_ThirdMap::OpenNextLevel()
{
	UEngineAPICore::GetCore()->OpenLevel("Play_FourthMap");
}

