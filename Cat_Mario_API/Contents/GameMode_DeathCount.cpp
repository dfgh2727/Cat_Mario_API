#include "PreCompile.h"
#include "GameMode_DeathCount.h"

#include <EngineCore/Level.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "DeathCount.h"
#include "MarioCat.h"
#include "CountDown.h"
#include "Enum.h"

#include "GameMode_FirstMap.h"
#include "GameMode_SecondMap.h"
#include "GameMode_ThirdMap.h"
#include "GameMode_FourthMap.h"
//#include "DownStair.h"

int GameMode_DeathCount::Number = 2;
std::string GameMode_DeathCount::MapNameString = "First";

bool GameMode_DeathCount::At1stMap = false;
bool GameMode_DeathCount::At2ndMap = false;
bool GameMode_DeathCount::At3rdMap = false;
bool GameMode_DeathCount::At4thMap = false;

GameMode_DeathCount::GameMode_DeathCount()
{
}

GameMode_DeathCount::~GameMode_DeathCount()
{
}

void GameMode_DeathCount::BeginPlay()
{
	Super::BeginPlay();

	{
		DeathCount* NewActor = GetWorld()->SpawnActor<DeathCount>();
	}

	{
		Counter = GetWorld()->SpawnActor<CountDown>();
		Counter->SetActorLocation({550, 420});
		Counter->SetTextSpriteName("CMnum.PNG");
		Counter->SetOrder(ERenderOrder::UI);
		Counter->SetTextScale({ 25, 50 });
		Counter->SetValue(Number);
	}
}

void GameMode_DeathCount::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	DeathCounter();

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_" + MapNameString + "Map");
	}

}

void GameMode_DeathCount::DeathCounter()
{
	Count = Number;

	if (Number < 0)
	{
		Count = Number * (-1);
		Counter->ShowMinus();
	}

	Counter->SetValue(Count);
}


void GameMode_DeathCount::GoToNextLevel()
{
	UEngineAPICore::GetCore()->OpenLevel("Play_" + MapNameString + "Map");
}

void GameMode_DeathCount::RestartLevel()
{
	if (At1stMap == true)
	{
		UEngineAPICore::GetCore()->ResetLevel<GameMode_FirstMap, MarioCat>("Play_" + MapNameString + "Map");
		UEngineAPICore::GetCore()->OpenLevel("Play_" + MapNameString + "Map");
	}

	if (At2ndMap == true)
	{
		UEngineAPICore::GetCore()->ResetLevel<GameMode_SecondMap, MarioCat>("Play_" + MapNameString + "Map");
		UEngineAPICore::GetCore()->OpenLevel("Play_" + MapNameString + "Map");
	}

	if (At3rdMap == true)
	{
		UEngineAPICore::GetCore()->ResetLevel<GameMode_ThirdMap, MarioCat>("Play_" + MapNameString + "Map");
		UEngineAPICore::GetCore()->OpenLevel("Play_" + MapNameString + "Map");
	}

	if (At4thMap == true)
	{
		UEngineAPICore::GetCore()->ResetLevel<GameMode_FourthMap, MarioCat>("Play_" + MapNameString + "Map");
		UEngineAPICore::GetCore()->OpenLevel("Play_" + MapNameString + "Map");
	}

}

void GameMode_DeathCount::LevelChangeStart()
{
	Super::LevelChangeStart();

	if (MarioCat::IsCatDead == true)
	{
		TimeEventer.PushEvent(2.0f, std::bind(&GameMode_DeathCount::RestartLevel, this));
	}
	else
	{
		TimeEventer.PushEvent(2.0f, std::bind(&GameMode_DeathCount::GoToNextLevel, this));
	}

	MarioCat::IsCatDead = false;
	MarioCat::IsCatKilled = false;
}