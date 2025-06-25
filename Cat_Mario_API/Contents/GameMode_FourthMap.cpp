#include "PreCompile.h"
#include "GameMode_FourthMap.h"

#include <EngineCore/Level.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "FourthMap.h"
#include "GameMode_DeathCount.h"
#include "MarioCat.h"

#include "Staff.h"
#include "FakeStaff.h"
#include "Bear.h"


GameMode_FourthMap::GameMode_FourthMap()
{
}

GameMode_FourthMap::~GameMode_FourthMap()
{
}

void GameMode_FourthMap::BeginPlay()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	Player->SetMapImage("4thMap.png");
	Player->SetColImage("4thColMap.png");

	{
		FourthMap* NewActor = GetWorld()->SpawnActor<FourthMap>();
	}
	{
		Staff* TheStaff = GetWorld()->SpawnActor<Staff>();
		TheStaff->SetActorLocation({ 1537, 374 });
	}
	{
		TheFStaff = GetWorld()->SpawnActor<FakeStaff>();
		TheFStaff->SetActorLocation({ 1131, 364 });
		TheFStaff->SetColImage("4thColMap.png");
	}

	BGMPlayer = UEngineSound::Play("Field.MP3");
	BGMPlayer.Loop(10);
}

void GameMode_FourthMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ReStart(_DeltaTime);

	BearSwitch();
	BearShowUp();

	StopTheMusic();

	FSSwitch();
	AtTheDoor();
	Clear();

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		UEngineAPICore::GetCore()->OpenLevel("TheEnd");
	}

}

void GameMode_FourthMap::StopTheMusic()
{
	if (true == SoundSwtich) //사망시 함수가 1번만 실행되게 만듦
	{
		MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
		if (Player->IsCatKilled == true || Player->GetPlayerState() == PlayerState::Dead)
		{
			BGMPlayer.Stop();
			DeathSoundPlayer = UEngineSound::Play("Death.MP3");
			SoundSwtich = false;
		}
	}
}

void GameMode_FourthMap::FSSwitch()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	FVector2D PlayerPos = Player->GetActorLocation();

	if (DoItOnce == true)
	{
		if (PlayerPos.X >= 840.0f && PlayerPos.X <= 1119.0f && PlayerPos.Y >= 640.0f)
		{
			TheFStaff->MoveSwitch = true;
			TheFStaff->GoLeft = true;
			DoItOnce = false;
		}
		else if (PlayerPos.X >= 1130.0f )
		{
			TheFStaff->MoveSwitch = true;
			TheFStaff->GoRight = true;
			DoItOnce = false;
		}
	}
}

void GameMode_FourthMap::ReStart(float _DeltaTime)
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();

	if (true == Player->IsCatDead)
	{
		--GameMode_DeathCount::Number;
		GameMode_DeathCount::At4thMap = true;
		GoToDeathCount();
	}
}

void GameMode_FourthMap::LevelChangeStart()
{
	Super::LevelChangeStart();

	static bool /*GameMode_FourthMap::*/Check = false;

	if (Check == false)
	{
		MarioCat::StartPos = { 175, 580 };
		Check = true;
	}
}

void GameMode_FourthMap::AtTheDoor()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	FVector2D PlayerPos = Player->GetActorLocation();
	if (PlayerPos.X >= 1885.0f)
	{
		Player->AtTheDoor = true;
	}
}

void GameMode_FourthMap::Clear()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	if (Player->Cleared == true)
	{
		BGMPlayer.Stop();
		//GameMode_DeathCount::MapNameString = "TheEnd";
		GameMode_DeathCount::At4thMap = false;

		MarioCat::StartPos = { 300, 700 };
		TimeEventer.PushEvent(3.5f, std::bind(&GameMode_FourthMap::GoToTheEnd, this));
	}
}

void GameMode_FourthMap::GoToDeathCount()
{
	UEngineAPICore::GetCore()->OpenLevel("DeathCount");
}

void GameMode_FourthMap::GoToTheEnd()
{
	UEngineAPICore::GetCore()->OpenLevel("TheEnd");
}

void GameMode_FourthMap::BearSwitch()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	FVector2D PlayerPos = Player->GetActorLocation();
	if (230.0f <= PlayerPos.X)
	{
		BearLever = true;
	}
}

void GameMode_FourthMap::BearShowUp()
{
	if (BearLever == true && DoItOnce2 == true)
	{
		Bear* NewActor = GetWorld()->SpawnActor<Bear>();
		NewActor->SetActorLocation({ 175, 600 });
		NewActor->SetColImage("4thColMap.png");
		NewActor->GoRight = true;
		
		BearLever = false;
		DoItOnce2 = false;
	}
}


