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
#include "QBlockwithCoin.h"
#include "QBlockwithWC.h"
#include "FirstMapP1.h"
#include "FirstMapP2.h"
#include "Seal.h"
#include "HiddenBoxS.h"
#include "SuperBouncyWC.h"
#include "Turtle.h"
#include "Staff.h"

#include "GameMode_DeathCount.h"



GameMode_FirstMap::GameMode_FirstMap()
{
}

GameMode_FirstMap::~GameMode_FirstMap()
{
}

void GameMode_FirstMap::BeginPlay()
{
	FirstMap* NewActor = GetWorld()->SpawnActor<FirstMap>();
	
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	Player->SetMapImage("1stMap.png");
	Player->SetColImage("1stColMap.png");


	/*if(MarioCat::TouchFlag == false)*/
	{
		Flag* MiddlePointFlag = GetWorld()->SpawnActor<Flag>();
		MiddlePointFlag->SetActorLocation({ 3860, 440 });
	}
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
		NewActor->SetActorLocation({ 843, 296 });

		QBlockwithWC* QMark = GetWorld()->SpawnActor<QBlockwithWC>();
		QMark->SetActorLocation({ 843, 296 });
		QMark->SetColImage("1stColMap.png");
	}
	{
		BNormalBlock* NewActor = GetWorld()->SpawnActor<BNormalBlock>();
		NewActor->SetActorLocation({ 785, 528 });
	
		QBlockwithCoin* QBlock = GetWorld()->SpawnActor<QBlockwithCoin>();
		QBlock->SetActorLocation({ 785, 528 });
	}

	//QMark->SetActorLocation({ 785, 528 });
	{
		BNormalBlock* NewActor = GetWorld()->SpawnActor<BNormalBlock>();
		NewActor->SetActorLocation({ 901, 528 });
	
		QBlockwithCoin* QBlock = GetWorld()->SpawnActor<QBlockwithCoin>();
		QBlock->SetActorLocation({ 901, 528 });
	}
	{
		WhiteCircle* NewActor = GetWorld()->SpawnActor<WhiteCircle>();
		NewActor->SetActorLocation({ 450, 700 });
		NewActor->SetColImage("1stColMap.png");
	}

	//테스트용
	{
		Turtle* NewActor = GetWorld()->SpawnActor<Turtle>();
		NewActor->SetActorLocation({ 400, 700 });
		NewActor->SetColImage("1stColMap.png");
	}
	{
		FirstMapP1* NewActor = GetWorld()->SpawnActor<FirstMapP1>();
		NewActor->SetActorLocation({ 1221, 646 });
	}
	{
		Seal1 = GetWorld()->SpawnActor<Seal>();
		Seal1->SetActorLocation({ 1221, 640 });
	}

	{
		HiddenBoxS* NewActor = GetWorld()->SpawnActor<HiddenBoxS>();
		NewActor->SetActorLocation({ 2358, 528 });
	}

	{
		FirstMapP2* NewActor = GetWorld()->SpawnActor<FirstMapP2>();
		NewActor->SetActorLocation({ 1753, 618 });
	}
	{
		SuperBouncyWC* NewActor = GetWorld()->SpawnActor<SuperBouncyWC>();
		NewActor->SetActorLocation({ 1450, 700 });
		NewActor->SetColImage("1stColMap.png");
	}

	{
		Seal2 = GetWorld()->SpawnActor<Seal>();
		Seal2->SetActorLocation({ 7280, -100 });
	}
	{
		Staff* TheStaff = GetWorld()->SpawnActor<Staff>();
		TheStaff->SetActorLocation({ 7161, 374 });
	}
}

void GameMode_FirstMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ReStart(_DeltaTime);

	Seal1Swtich();
	//SealGoUp();

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

void GameMode_FirstMap::LevelChangeStart()
{
	Super::LevelChangeStart();

	static bool /*GameMode_FirstMap::*/Check = false;

	if (Check == false)
	{
		MarioCat::StartPos = { 300, 700 };
		Check = true;
	}
}

void GameMode_FirstMap::Seal1Swtich()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	FVector2D PlayerPos = Player->GetActorLocation();
	if(PlayerPos.X >= 1160.0f && PlayerPos.Y <= 520.0f)
	{
		Seal1Lever = true;
	}
}

void GameMode_FirstMap::Seal2Swtich()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	FVector2D PlayerPos = Player->GetActorLocation();
	if (PlayerPos.X >= 1120.0f && PlayerPos.Y <= 520.0f)
	{
		Seal1Lever = true;
	}
}


void GameMode_FirstMap::SealGoUp()
{
	if (Seal1Lever == true)
	{
		Seal1->AddActorLocation(FVector2D::UP * 0.8f);
	}
}

void GameMode_FirstMap::SealGoDown()
{
	if (Seal2Lever == true)
	{
		Seal1->AddActorLocation(FVector2D::UP * 0.8f);
	}
}

