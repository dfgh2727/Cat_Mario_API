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
#include "QBlockwithMushroomN.h"
#include "FirstMapP1.h"
#include "FirstMapP2.h"
#include "ColPipe.h"
#include "UpSeal.h"
#include "DownSeal.h"
#include "HiddenBoxS.h"
#include "SuperBouncyWC.h"
#include "Turtle.h"
#include "Staff.h"

#include "FDBlock1.h"
#include "FDBlock2.h"
#include "Cloud.h"
#include "InfiniteCoinBox.h"

#include "FlyingStick.h"
#include "Star.h"

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
		HiddenBoxS* NewActor = GetWorld()->SpawnActor<HiddenBoxS>();
		NewActor->SetActorLocation({ 785, 587 });
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

	{
		BNormalBlock* NewActor = GetWorld()->SpawnActor<BNormalBlock>();
		NewActor->SetActorLocation({ 901, 528 });
	
		QBlockwithCoin* QBlock = GetWorld()->SpawnActor<QBlockwithCoin>();
		QBlock->SetActorLocation({ 901, 528 });
	}
	//{
	//	WhiteCircle* NewActor = GetWorld()->SpawnActor<WhiteCircle>();
	//	NewActor->SetActorLocation({ 610, 700 });
	//	NewActor->SetColImage("1stColMap.png");
	//}
	//{
	//	WhiteCircle* NewActor = GetWorld()->SpawnActor<WhiteCircle>();
	//	NewActor->SetActorLocation({ 955, 700 });
	//	NewActor->SetColImage("1stColMap.png");
	//}

	//테스트용
	{
		/*Turtle* NewActor = GetWorld()->SpawnActor<Turtle>();
		NewActor->SetActorLocation({ 400, 700 });
		NewActor->SetColImage("1stColMap.png");*/
	}
	{
		FirstMapP1* NewActor = GetWorld()->SpawnActor<FirstMapP1>();
		NewActor->SetActorLocation({ 1221, 646 });
	}
	{
		Seal1 = GetWorld()->SpawnActor<UpSeal>();
		Seal1->SetActorLocation({ 1221, 640 });
	}

	{
		HiddenBoxS* NewActor = GetWorld()->SpawnActor<HiddenBoxS>();
		NewActor->SetActorLocation({ 2358, 528 });
	}

	{
		FirstMapP2* NewActor = GetWorld()->SpawnActor<FirstMapP2>();
		NewActor->SetActorLocation({ 1753, 617 });
	}
	{
		ColPipe* NewActor = GetWorld()->SpawnActor<ColPipe>();
		NewActor->SetActorLocation({ 1753, 617 });
	}
	{
		SuperBouncyWC* NewActor = GetWorld()->SpawnActor<SuperBouncyWC>();
		NewActor->SetActorLocation({ 1450, 700 });
		NewActor->SetColImage("1stColMap.png");
	}

	{
		Seal2 = GetWorld()->SpawnActor<DownSeal>();
		Seal2->SetActorLocation({ 3180, -100 });
	}

	{
		BBreakingBlock* NewActor = GetWorld()->SpawnActor<BBreakingBlock>();
		NewActor->SetActorLocation({ 2698, 528 });
	}
	{
		BNormalBlock* NewActor = GetWorld()->SpawnActor<BNormalBlock>();
		NewActor->SetActorLocation({ 2756, 528 });

		QBlockwithMushroomN* QBlock = GetWorld()->SpawnActor<QBlockwithMushroomN>();
		QBlock->SetActorLocation({ 2756, 528 });
		QBlock->SetColImage("1stColMap.png");

	}
	{
		BBreakingBlock* NewActor = GetWorld()->SpawnActor<BBreakingBlock>();
		NewActor->SetActorLocation({ 2814, 528 });
	}

	{
		FDBlock1* NewActor = GetWorld()->SpawnActor<FDBlock1>();
		NewActor->SetActorLocation({ 2929, 296});
	}

	{
		BBreakingBlock* NewActor = GetWorld()->SpawnActor<BBreakingBlock>();
		NewActor->SetActorLocation({ 3335, 296 });
	}
	{
		BBreakingBlock* NewActor = GetWorld()->SpawnActor<BBreakingBlock>();
		NewActor->SetActorLocation({ 3393, 296 });
	}
	{
		BBreakingBlock* NewActor = GetWorld()->SpawnActor<BBreakingBlock>();
		NewActor->SetActorLocation({ 3451, 296 });
	}

	{
		//사라지는 QBlock 배치
	}
	{
		InfiniteCoinBox* NewActor = GetWorld()->SpawnActor<InfiniteCoinBox>();
		NewActor->SetActorLocation({ 3451, 528 });
	}

	{
		BBreakingBlock* NewActor = GetWorld()->SpawnActor<BBreakingBlock>();
		NewActor->SetActorLocation({ 3857, 528 });
	}
	{
		Star* NewActor = GetWorld()->SpawnActor<Star>();
		NewActor->SetActorLocation({ 2920, 500 });
		NewActor->SetColImage("1stColMap.png");

	}

	{
		BNormalBlock* NewActor = GetWorld()->SpawnActor<BNormalBlock>();
		NewActor->SetActorLocation({4147, 528 });

		QBlockwithCoin* QBlock = GetWorld()->SpawnActor<QBlockwithCoin>();
		QBlock->SetActorLocation({4147, 528 });
	}
	{
		BNormalBlock* NewActor = GetWorld()->SpawnActor<BNormalBlock>();
		NewActor->SetActorLocation({ 4321, 528 });

		QBlockwithCoin* QBlock = GetWorld()->SpawnActor<QBlockwithCoin>();
		QBlock->SetActorLocation({4321, 528 });
	}
	{
		BNormalBlock* NewActor = GetWorld()->SpawnActor<BNormalBlock>();
		NewActor->SetActorLocation({ 4321, 296 });

		QBlockwithCoin* QBlock = GetWorld()->SpawnActor<QBlockwithCoin>();
		QBlock->SetActorLocation({ 4321, 296 });
	}
	{
		BNormalBlock* NewActor = GetWorld()->SpawnActor<BNormalBlock>();
		NewActor->SetActorLocation({ 4493, 528 });

		QBlockwithCoin* QBlock = GetWorld()->SpawnActor<QBlockwithCoin>();
		QBlock->SetActorLocation({ 4493, 528 });
	}
	{
		FDBlock2* NewActor = GetWorld()->SpawnActor<FDBlock2>();
		NewActor->SetActorLocation({ 4321, 785 });
	}

	{
		HiddenBoxS* NewActor = GetWorld()->SpawnActor<HiddenBoxS>();
		NewActor->SetActorLocation({ 5190, 354 });
	}
	{
		HiddenBoxS* NewActor = GetWorld()->SpawnActor<HiddenBoxS>();
		NewActor->SetActorLocation({ 5248, 587 });
	}
	{
		HiddenBoxS* NewActor = GetWorld()->SpawnActor<HiddenBoxS>();
		NewActor->SetActorLocation({ 5305, 587 });
	}
	{
		HiddenBoxS* NewActor = GetWorld()->SpawnActor<HiddenBoxS>();
		NewActor->SetActorLocation({ 5362, 587 });
	}
	{
		HiddenBoxS* NewActor = GetWorld()->SpawnActor<HiddenBoxS>();
		NewActor->SetActorLocation({ 5419, 587 });
	}
	{
		HiddenBoxS* NewActor = GetWorld()->SpawnActor<HiddenBoxS>();
		NewActor->SetActorLocation({ 5477, 587 });
	}

	{
		BBreakingBlock* NewActor = GetWorld()->SpawnActor<BBreakingBlock>();
		NewActor->SetActorLocation({ 5768, 528 });
	}
	{
		BBreakingBlock* NewActor = GetWorld()->SpawnActor<BBreakingBlock>();
		NewActor->SetActorLocation({ 5826, 528 });
	}
	{
		BNormalBlock* NewActor = GetWorld()->SpawnActor<BNormalBlock>();
		NewActor->SetActorLocation({ 5884, 528 });

		QBlockwithCoin* QBlock = GetWorld()->SpawnActor<QBlockwithCoin>();
		QBlock->SetActorLocation({ 5884, 528 });
	}
	{
		BBreakingBlock* NewActor = GetWorld()->SpawnActor<BBreakingBlock>();
		NewActor->SetActorLocation({ 5942, 528 });
	}

	{
		Cloud* NewActor = GetWorld()->SpawnActor<Cloud>();
		NewActor->SetActorLocation({ 6040, 326 });
	}

	// 날아오는 막대기 구현

	{
		Seal3 = GetWorld()->SpawnActor<DownSeal>();
		Seal3->SetActorLocation({ 7380, -100 });
	}
	{
		Staff* TheStaff = GetWorld()->SpawnActor<Staff>();
		TheStaff->SetActorLocation({ 7161, 374 });
	}

	//BGMPlayerBase = UEngineSound::Play("Field.MP3");
}

void GameMode_FirstMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	ReStart(_DeltaTime);

	SealSwtich();
	//SealGoUp();
	//SealGoDown();

	FSSwtich();
	FlyingStickAppears();

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_SecondMap");
	}

	//StopTheMusic();
	OverTheStaff();
	AtTheDoor();
	Clear();
}

void GameMode_FirstMap::StopTheMusic()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	if (Player->IsCatKilled == true)
	{
		BGMPlayerBase.Stop();
	}
}

void GameMode_FirstMap::ReStart(float _DeltaTime)
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();

	if (true == Player->IsCatDead)
	{
		--GameMode_DeathCount::Number;
		GameMode_DeathCount::At1stMap = true;
		GoToDeathCount();
	}
}

void GameMode_FirstMap::LevelChangeStart()
{
	Super::LevelChangeStart();

	static bool /*GameMode_FirstMap::*/Check = false;

	if (Check == false)
	{
		MarioCat::StartPos = { 2920, 700 /*5940, 700*/ /*300, 700*/ /*7100, 10*/  /*6700, 10*/ };
		Check = true;
	}
}

void GameMode_FirstMap::SealSwtich()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	FVector2D PlayerPos = Player->GetActorLocation();
	if(PlayerPos.X >= 1160.0f && PlayerPos.Y <= 520.0f)
	{
		Seal1Lever = true;
	}

	if (PlayerPos.X >= 3120.0f)
	{
		Seal2Lever = true;
	}

	if (PlayerPos.X >= 7250.0f)
	{
		Seal3Lever = true;
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
		Seal2->AddActorLocation(FVector2D::DOWN * 0.8f);
	}

	if (Seal3Lever == true)
	{
		Seal3->AddActorLocation(FVector2D::DOWN * 0.8f);
	}
}

void GameMode_FirstMap::OverTheStaff()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	FVector2D PlayerPos = Player->GetActorLocation();
	if (PlayerPos.X >= 7161.0f)
	{
		Player->OverTheStaff = true;
	}	
}

void GameMode_FirstMap::AtTheDoor()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	FVector2D PlayerPos = Player->GetActorLocation();
	if (PlayerPos.X >= 7510.0f)
	{
		Player->AtTheDoor = true;
	}
}

void GameMode_FirstMap::Clear()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	if (Player->Cleared == true)
	{
		GameMode_DeathCount::MapNameString = "Second";
		GameMode_DeathCount::At1stMap = false;

		MarioCat::StartPos = { 150, 700 };
		TimeEventer.PushEvent(2.0f, std::bind(&GameMode_FirstMap::GoToDeathCount, this));
	}
}

void GameMode_FirstMap::GoToDeathCount()
{
	UEngineAPICore::GetCore()->OpenLevel("DeathCount");
}

void GameMode_FirstMap::FSSwtich()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	FVector2D PlayerPos = Player->GetActorLocation();

	if (PlayerPos.X >= 6770.0f && PlayerPos.Y <= 80.0f)
	{
		FSLever = true;
	}
}

void GameMode_FirstMap::FlyingStickAppears()
{
	if (FSLever == true && DoItOnce == 1)
	{
		FlyingStick* NewActor = GetWorld()->SpawnActor<FlyingStick>();
		NewActor->SetActorLocation({ 6900, 100 });
		--DoItOnce;
	}
}

