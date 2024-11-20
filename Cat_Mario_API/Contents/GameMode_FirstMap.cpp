#include "PreCompile.h"
#include "GameMode_FirstMap.h"

#include <EngineCore/Level.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "FirstMap.h"
#include "MarioCat.h"
#include "BBreakingBlock.h"
#include "GoingUpBlock.h"
#include "BNormalBlock.h"
#include "WhiteCircle.h"
#include "MapActor.h"

#include "GameMode_DeathCount.h"



GameMode_FirstMap::GameMode_FirstMap()
{
}

GameMode_FirstMap::~GameMode_FirstMap()
{
}

void GameMode_FirstMap::BeginPlay()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	Player->SetMapImage("1stMap.png");
	Player->SetColImage("1stColMap.png");
	
	FirstMap* NewActor = GetWorld()->SpawnActor<FirstMap>();

	{
		GoingUpBlock* NewActor = GetWorld()->SpawnActor<GoingUpBlock>();
		NewActor->SetActorLocation({ 494, 528 });
	}
	{
		BBreakingBlock* NewActor = GetWorld()->SpawnActor<BBreakingBlock>();
		NewActor->SetActorLocation({ 727, 528 });
	}
	{
		BBreakingBlock* NewActor = GetWorld()->SpawnActor<BBreakingBlock>();
		NewActor->SetActorLocation({ 843, 528 });
	}
	{
		BBreakingBlock* NewActor = GetWorld()->SpawnActor<BBreakingBlock>();
		NewActor->SetActorLocation({ 959, 528 });
	}
	{
		BNormalBlock* NewActor = GetWorld()->SpawnActor<BNormalBlock>();
		NewActor->SetActorLocation({ 785, 528 });
	}
	{
		WhiteCircle* NewActor = GetWorld()->SpawnActor<WhiteCircle>();
		NewActor->SetActorLocation({ 450, 700 });
		NewActor->SetColImage("1stColMap.png");
	}
}

void GameMode_FirstMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ReStart(_DeltaTime);


	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_SecondMap");
	}

}

void GameMode_FirstMap::ReStart(float _DeltaTime)
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	GameMode_DeathCount* Counter = GetWorld()->GetGameMode<GameMode_DeathCount>();

	if (true == Player->IsCatDead)
	{
		/*UEngineAPICore::GetCore()->OpenLevel("DeathCount");
		Counter->Count;
		*/
		UEngineAPICore::GetCore()->ResetLevel<GameMode_FirstMap, MarioCat>("Play_FirstMap");
		UEngineAPICore::GetCore()->OpenLevel("Play_FirstMap");
	}
}

