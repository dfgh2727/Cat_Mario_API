#include "PreCompile.h"

#include "GameMode_SecondMap.h"

#include <EngineCore/Level.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "SecondMap.h"
#include "MarioCat.h"

#include "SecondMapP2.h"
#include "UpSeal.h"

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
		SecondMapP2* NewActor = GetWorld()->SpawnActor<SecondMapP2>();
		NewActor->SetActorLocation({ 882, 617 });
	}
	{
		Seal = GetWorld()->SpawnActor<UpSeal>();
		Seal->SetActorLocation({ 882, 617 });
	}
}

void GameMode_SecondMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_ThirdMap");
	}

}

void GameMode_SecondMap::LevelChangeStart()
{
	Super::LevelChangeStart();

	static bool /*GameMode_FirstMap::*/Check = false;

	if (Check == false)
	{
		MarioCat::StartPos = { 300, 700 };
		Check = true;
	}
}
