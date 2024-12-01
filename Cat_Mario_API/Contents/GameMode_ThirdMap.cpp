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
#include "HiddenBoxD.h"
#include "HiddenBoxDT.h"
#include "KingWC.h"

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
		HiddenBoxD* NewActor = GetWorld()->SpawnActor<HiddenBoxD>();
		NewActor->SetActorLocation({ 146, 701 });
	}

	{
		HiddenBoxD* NewActor = GetWorld()->SpawnActor<HiddenBoxD>();
		NewActor->SetActorLocation({ 1130, 470 });
	}
	{
		FDBlock3* NewActor = GetWorld()->SpawnActor<FDBlock3>();
		NewActor->SetActorLocation({ 1421, 786 });
	}

	{
		HiddenBoxD* NewActor = GetWorld()->SpawnActor<HiddenBoxD>();
		NewActor->SetActorLocation({ 1247, 528 });
	}
	{
		HiddenBoxD* NewActor = GetWorld()->SpawnActor<HiddenBoxD>();
		NewActor->SetActorLocation({ 1305, 528 });
	}
	{
		HiddenBoxD* NewActor = GetWorld()->SpawnActor<HiddenBoxD>();
		NewActor->SetActorLocation({ 1363, 528 });
	} 
	{
		HiddenBoxD* NewActor = GetWorld()->SpawnActor<HiddenBoxD>();
		NewActor->SetActorLocation({ 1421, 528 });
	}

	{
		HiddenBoxDT* NewActor = GetWorld()->SpawnActor<HiddenBoxDT>();
		NewActor->SetActorLocation({ 2290, 701 });
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

	KWCSwitch();
	KWCShowUp();

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

void GameMode_ThirdMap::KWCSwitch()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	FVector2D PlayerPos = Player->GetActorLocation();
	if (PlayerPos.X >= 2440.0f)
	{
		KWCLever = true;
	}
}

void GameMode_ThirdMap::KWCShowUp()
{
	if (KWCLever == true && DoItOnce1 == true)
	{
		KingWC* NewActor = GetWorld()->SpawnActor<KingWC>();
		NewActor->SetActorLocation({ 2550, 820 });
		NewActor->SetColImage("3rdColMap.png");
		DoItOnce1 = false;
	}
}
