#include "PreCompile.h"
#include "GameMode_SecondMap.h"

#include <EngineCore/Level.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "SecondMap.h"

#include "MarioCat.h"
#include "SecondMapP1.h"
#include "SecondMapP2.h"
#include "ColPipe.h"
#include "UpSeal.h"

#include "GameMode_DeathCount.h"

GameMode_SecondMap::GameMode_SecondMap()
{
}

GameMode_SecondMap::~GameMode_SecondMap()
{
}

void GameMode_SecondMap::BeginPlay()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	Player->SetMapImage("2ndMap.png");
	Player->SetColImage("2ndColMap.png");

	{
		SecondMap* NewActor = GetWorld()->SpawnActor<SecondMap>();
	}
	{
		SecondMapP1* NewActor = GetWorld()->SpawnActor<SecondMapP1>();
		NewActor->SetActorLocation({ 766, 674 });
	}
	{
		SecondMapP2* NewActor = GetWorld()->SpawnActor<SecondMapP2>();
		NewActor->SetActorLocation({ 882, 617 });
	}
	{
		ColPipe* Col = GetWorld()->SpawnActor<ColPipe>();
		Col->SetActorLocation({ 882, 617 });
	}
	{
		Seal = GetWorld()->SpawnActor<UpSeal>();
		Seal->SetActorLocation({ 882, 617 });
	}
}

void GameMode_SecondMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	SealSwitch();
	LaunchTheSeal();

	ReStart(_DeltaTime);
	Clear();

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_ThirdMap");

	}
}

void GameMode_SecondMap::LevelChangeStart()
{
	Super::LevelChangeStart();

	static bool Check = false;

	if (Check == false)
	{
		MarioCat::StartPos = { 150, 700 };
		Check = true;
	}
}

void GameMode_SecondMap::SealSwitch()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	FVector2D PlayerPos = Player->GetActorLocation();
	if (PlayerPos.X >= 800.0f)
	{
		SwitchLever = true;
	}
}


void GameMode_SecondMap::LaunchTheSeal()
{
	if (SwitchLever == true)
	{
		Seal->AddActorLocation(FVector2D::UP * 0.8f);
	}
}

void GameMode_SecondMap::ReStart(float _DeltaTime)
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();

	if (true == Player->IsCatDead)
	{
		--GameMode_DeathCount::Number;
		GameMode_DeathCount::At2ndMap = true;

		GoToDeathCount();
	}
}

void GameMode_SecondMap::GoToDeathCount()
{
	UEngineAPICore::GetCore()->OpenLevel("DeathCount");
}

void GameMode_SecondMap::Clear()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();

	if (Player->InThePipe == true)
	{
		GameMode_DeathCount::MapNameString = "Third";
		GameMode_DeathCount::At2ndMap = false;

		MarioCat::StartPos = { 148, 10 };
		TimeEventer.PushEvent(0.5f, std::bind(&GameMode_SecondMap::OpenNextLevel, this));
	}
}

void GameMode_SecondMap::OpenNextLevel()
{
	UEngineAPICore::GetCore()->OpenLevel("Play_ThirdMap");
}
