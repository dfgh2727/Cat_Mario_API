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
#include "Flag.h"

#include "GameMode_DeathCount.h"



GameMode_FirstMap::GameMode_FirstMap()
{
}

GameMode_FirstMap::~GameMode_FirstMap()
{
}

void GameMode_FirstMap::BeginPlay()
{
	FVector2D FlagPos = { 959, 443 };
	
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	Player->SetMapImage("1stMap.png");
	Player->SetColImage("1stColMap.png");

	if (MarioCat::TouchFlag == false)
	{
		SetActorLocation({ 300, 700 });
	}
	else
	{
		SetActorLocation(FlagPos);
	}
	
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

	if(MarioCat::TouchFlag == false)
	{
		MiddlePointFlag = GetWorld()->SpawnActor<Flag>();
		MiddlePointFlag->SetActorLocation(FlagPos);
	}
}

void GameMode_FirstMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ReStart(_DeltaTime);
	IsFlagGone();

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_SecondMap");
	}

}

void GameMode_FirstMap::ReStart(float _DeltaTime)
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();

	if (true == Player->IsCatDead)
	{
		--GameMode_DeathCount::Number;

		UEngineAPICore::GetCore()->OpenLevel("DeathCount");
		
		/*UEngineAPICore::GetCore()->ResetLevel<GameMode_FirstMap, MarioCat>("Play_FirstMap");
		UEngineAPICore::GetCore()->OpenLevel("Play_FirstMap");*/
	}
}

void GameMode_FirstMap::IsFlagGone()
{
	if (MiddlePointFlag = nullptr)
	{
		MarioCat::TouchFlag = true;
	}
}
