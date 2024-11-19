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


GameMode_FirstMap::GameMode_FirstMap()
{
}

GameMode_FirstMap::~GameMode_FirstMap()
{
}

void GameMode_FirstMap::BeginPlay()
{
	Player = GetWorld()->GetPawn<MarioCat>();
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
		NewActor->SetActorLocation({ 300, 700 });
	}
}

void GameMode_FirstMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_SecondMap");
	}

}


