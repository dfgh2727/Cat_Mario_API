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
#include "HiddenBoxFragile.h"
#include "Flag.h"
#include "ThirdMapP1.h"
#include "Bear.h"
#include "FDBlock4.h"
#include "FDBlock5.h"
#include "FDBlock6.h"
#include "FDBlock7.h"
#include "FireBallSwitch.h"
#include "UpStair.h"
#include "DownStair.h"
#include "GAbnormalBlock.h"
#include "ThirdMapP2.h"
#include "ColPipe2.h"

#include "WhiteCircle.h"
#include "MapActor.h"
#include "QBlockwithCoin.h"
#include "QBlockwithWC.h"
#include "QBlockwithMushroom.h"
#include "Turtle.h"
#include "StarBox.h"
#include "BNormalBlock.h"

#include "GBTileBlock.h"
#include "GBBrick.h"
#include "GBMarbleBlock1.h"
#include "GBMarbleBlock2.h"


//bool GameMode_ThirdMap::CatIsOnStair = false;

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

	//BigBody 전용 BreakingBlock (Tile)
	{
		GBTileBlock* NewActor = GetWorld()->SpawnActor<GBTileBlock>();
		NewActor->SetActorLocation({ 4784, 528 });
	}
	{
		GBTileBlock* NewActor = GetWorld()->SpawnActor<GBTileBlock>();
		NewActor->SetActorLocation({ 4842, 528 });
	}
	{
		GBTileBlock* NewActor = GetWorld()->SpawnActor<GBTileBlock>();
		NewActor->SetActorLocation({ 4900, 528 });
	}
	{
		GBTileBlock* NewActor = GetWorld()->SpawnActor<GBTileBlock>();
		NewActor->SetActorLocation({ 4958, 528 });
	}

	{
		GBTileBlock* NewActor = GetWorld()->SpawnActor<GBTileBlock>();
		NewActor->SetActorLocation({ 4784, 586 });
	}
	{
		GBTileBlock* NewActor = GetWorld()->SpawnActor<GBTileBlock>();
		NewActor->SetActorLocation({ 4842, 586 });
	}
	{
		GBTileBlock* NewActor = GetWorld()->SpawnActor<GBTileBlock>();
		NewActor->SetActorLocation({ 4900, 586 });
	}
	{
		GBTileBlock* NewActor = GetWorld()->SpawnActor<GBTileBlock>();
		NewActor->SetActorLocation({ 4958, 586 });
	}

	{
		GBTileBlock* NewActor = GetWorld()->SpawnActor<GBTileBlock>();
		NewActor->SetActorLocation({ 4784, 644 });
	}
	{
		GBTileBlock* NewActor = GetWorld()->SpawnActor<GBTileBlock>();
		NewActor->SetActorLocation({ 4842, 644 });
	}
	{
		GBTileBlock* NewActor = GetWorld()->SpawnActor<GBTileBlock>();
		NewActor->SetActorLocation({ 4900, 644 });
	}
	{
		GBTileBlock* NewActor = GetWorld()->SpawnActor<GBTileBlock>();
		NewActor->SetActorLocation({ 4958, 644 });
	}

	{
		GBTileBlock* NewActor = GetWorld()->SpawnActor<GBTileBlock>();
		NewActor->SetActorLocation({ 4784, 702 });
	}
	{
		GBTileBlock* NewActor = GetWorld()->SpawnActor<GBTileBlock>();
		NewActor->SetActorLocation({ 4842, 702 });
	}
	{
		GBTileBlock* NewActor = GetWorld()->SpawnActor<GBTileBlock>();
		NewActor->SetActorLocation({ 4900, 702 });
	}
	{
		GBTileBlock* NewActor = GetWorld()->SpawnActor<GBTileBlock>();
		NewActor->SetActorLocation({ 4958, 702 });
	}

	//BigBody 전용 BreakingBlock (Brick)
	{
		GBBrick* NewActor = GetWorld()->SpawnActor<GBBrick>();
		NewActor->SetActorLocation({ 4726, 470 });
	}
	{
		GBBrick* NewActor = GetWorld()->SpawnActor<GBBrick>();
		NewActor->SetActorLocation({ 4726, 528 });
	}
	{
		GBBrick* NewActor = GetWorld()->SpawnActor<GBBrick>();
		NewActor->SetActorLocation({ 4726, 586 });
	}
	{
		GBBrick* NewActor = GetWorld()->SpawnActor<GBBrick>();
		NewActor->SetActorLocation({ 4726, 644 });
	}
	{
		GBBrick* NewActor = GetWorld()->SpawnActor<GBBrick>();
		NewActor->SetActorLocation({ 4726, 702 });
	}

	{
		GBBrick* NewActor = GetWorld()->SpawnActor<GBBrick>();
		NewActor->SetActorLocation({ 4668, 586 });
	}
	{
		GBBrick* NewActor = GetWorld()->SpawnActor<GBBrick>();
		NewActor->SetActorLocation({ 4668, 644 });
	}
	{
		GBBrick* NewActor = GetWorld()->SpawnActor<GBBrick>();
		NewActor->SetActorLocation({ 4668, 702 });
	}

	{
		GBBrick* NewActor = GetWorld()->SpawnActor<GBBrick>();
		NewActor->SetActorLocation({ 5016, 470 });
	}
	{
		GBBrick* NewActor = GetWorld()->SpawnActor<GBBrick>();
		NewActor->SetActorLocation({ 5016, 528 });
	}
	{
		GBBrick* NewActor = GetWorld()->SpawnActor<GBBrick>();
		NewActor->SetActorLocation({ 5016, 586 });
	}
	{
		GBBrick* NewActor = GetWorld()->SpawnActor<GBBrick>();
		NewActor->SetActorLocation({ 5016, 644 });
	}
	{
		GBBrick* NewActor = GetWorld()->SpawnActor<GBBrick>();
		NewActor->SetActorLocation({ 5016, 702 });
	}

	{
		GBBrick* NewActor = GetWorld()->SpawnActor<GBBrick>();
		NewActor->SetActorLocation({ 5074, 528 });
	}
	{
		GBBrick* NewActor = GetWorld()->SpawnActor<GBBrick>();
		NewActor->SetActorLocation({ 5074, 586 });
	}
	{
		GBBrick* NewActor = GetWorld()->SpawnActor<GBBrick>();
		NewActor->SetActorLocation({ 5074, 644 });
	}
	{
		GBBrick* NewActor = GetWorld()->SpawnActor<GBBrick>();
		NewActor->SetActorLocation({ 5074, 702 });
	}

	//BigBody 전용 BreakingBlock (MarbleBlock)
	{
		GBMarbleBlock1* NewActor = GetWorld()->SpawnActor<GBMarbleBlock1>();
		NewActor->SetActorLocation({ 4668, 760 });
	}
	{
		GBMarbleBlock1* NewActor = GetWorld()->SpawnActor<GBMarbleBlock1>();
		NewActor->SetActorLocation({ 4726, 760 });
	}
	{
		GBMarbleBlock1* NewActor = GetWorld()->SpawnActor<GBMarbleBlock1>();
		NewActor->SetActorLocation({ 4784, 760 });
	}
	{
		GBMarbleBlock1* NewActor = GetWorld()->SpawnActor<GBMarbleBlock1>();
		NewActor->SetActorLocation({ 4842, 760 });
	}
	{
		GBMarbleBlock1* NewActor = GetWorld()->SpawnActor<GBMarbleBlock1>();
		NewActor->SetActorLocation({ 4900, 760 });
	}
	{
		GBMarbleBlock1* NewActor = GetWorld()->SpawnActor<GBMarbleBlock1>();
		NewActor->SetActorLocation({ 4958, 760 });
	}
	{
		GBMarbleBlock1* NewActor = GetWorld()->SpawnActor<GBMarbleBlock1>();
		NewActor->SetActorLocation({ 5016, 760 });
	}
	{
		GBMarbleBlock1* NewActor = GetWorld()->SpawnActor<GBMarbleBlock1>();
		NewActor->SetActorLocation({ 5074, 760 });
	}

	{
		GBMarbleBlock1* NewActor = GetWorld()->SpawnActor<GBMarbleBlock1>();
		NewActor->SetActorLocation({ 4668, 818 });
	}
	{
		GBMarbleBlock1* NewActor = GetWorld()->SpawnActor<GBMarbleBlock1>();
		NewActor->SetActorLocation({ 4726, 818 });
	}
	{
		GBMarbleBlock1* NewActor = GetWorld()->SpawnActor<GBMarbleBlock1>();
		NewActor->SetActorLocation({ 4784, 818 });
	}
	{
		GBMarbleBlock1* NewActor = GetWorld()->SpawnActor<GBMarbleBlock1>();
		NewActor->SetActorLocation({ 4842, 818 });
	}
	{
		GBMarbleBlock1* NewActor = GetWorld()->SpawnActor<GBMarbleBlock1>();
		NewActor->SetActorLocation({ 4900, 818 });
	}
	{
		GBMarbleBlock1* NewActor = GetWorld()->SpawnActor<GBMarbleBlock1>();
		NewActor->SetActorLocation({ 4958, 818 });
	}
	{
		GBMarbleBlock1* NewActor = GetWorld()->SpawnActor<GBMarbleBlock1>();
		NewActor->SetActorLocation({ 5016, 818 });
	}
	{
		GBMarbleBlock1* NewActor = GetWorld()->SpawnActor<GBMarbleBlock1>();
		NewActor->SetActorLocation({ 5074, 818 });
	}

	{
		KingWC* NewActor = GetWorld()->SpawnActor<KingWC>();
		NewActor->SetActorLocation({4903, 464 });
		NewActor->SetColImage("3rdColMap.png");
	}

	{
		ThirdMap* NewActor = GetWorld()->SpawnActor<ThirdMap>();
	}

	{
		FDBlock3* NewActor = GetWorld()->SpawnActor<FDBlock3>();
		NewActor->SetActorLocation({ 146, 786 });
	}

	{
		BNormalBlock* NewActor = GetWorld()->SpawnActor<BNormalBlock>();
		NewActor->SetActorLocation({ 436, 528 });

		QBlockwithMushroom* QMark = GetWorld()->SpawnActor<QBlockwithMushroom>();
		QMark->SetActorLocation({ 436, 528 });
		QMark->SetColImage("3rdColMap.png");
	}
	{
		BNormalBlock* NewActor = GetWorld()->SpawnActor<BNormalBlock>();
		NewActor->SetActorLocation({ 610, 528 });

		QBlockwithWC* QMark = GetWorld()->SpawnActor<QBlockwithWC>();
		QMark->SetActorLocation({ 610, 528 });
		QMark->SetColImage("3rdColMap.png");
	}
	{
		BNormalBlock* NewActor = GetWorld()->SpawnActor<BNormalBlock>();
		NewActor->SetActorLocation({ 494, 528 });

		QBlockwithCoin* QBlock = GetWorld()->SpawnActor<QBlockwithCoin>();
		QBlock->SetActorLocation({ 494, 528 });
	}
	{
		BNormalBlock* NewActor = GetWorld()->SpawnActor<BNormalBlock>();
		NewActor->SetActorLocation({ 552, 528 });

		QBlockwithCoin* QBlock = GetWorld()->SpawnActor<QBlockwithCoin>();
		QBlock->SetActorLocation({ 552, 528 });
	}
	{
		WhiteCircle* NewActor = GetWorld()->SpawnActor<WhiteCircle>();
		NewActor->SetActorLocation({ 660, 700 });
		NewActor->SetColImage("3rdColMap.png");
	}
	{
		WhiteCircle* NewActor = GetWorld()->SpawnActor<WhiteCircle>();
		NewActor->SetActorLocation({ 780, 700 });
		NewActor->SetColImage("3rdColMap.png");
	}

	{
		GAbnormalBlock* NewActor = GetWorld()->SpawnActor<GAbnormalBlock>();
		NewActor->SetActorLocation({ 1073, 588 });
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
		WhiteCircle* NewActor = GetWorld()->SpawnActor<WhiteCircle>();
		NewActor->SetActorLocation({ 1305, 700 });
		NewActor->SetColImage("3rdColMap.png");
	}

	{
		HiddenBoxDT* NewActor = GetWorld()->SpawnActor<HiddenBoxDT>();
		NewActor->SetActorLocation({ 2291, 703 });
	}

	{
		HiddenBoxFragile* NewActor = GetWorld()->SpawnActor<HiddenBoxFragile>();
		NewActor->SetActorLocation({ 2864, 528 });
	}

	{
		ThirdMapP1* MiddlePointFlag = GetWorld()->SpawnActor<ThirdMapP1>();
		MiddlePointFlag->SetActorLocation({ 3191, 674 });
	}
	{
		Flag* MiddlePointFlag = GetWorld()->SpawnActor<Flag>();
		MiddlePointFlag->SetActorLocation({ 3570, 674 });
	}

	{
		FDB4 = GetWorld()->SpawnActor<FDBlock4>();
		FDB4->SetActorLocation({ 4177, 64 });
	}
	{
		FDB5 = GetWorld()->SpawnActor<FDBlock5>();
		FDB5->SetActorLocation({ 3915, 65 });
	}
	{
		FDB6 = GetWorld()->SpawnActor<FDBlock6>();
		FDB6->SetActorLocation({ 4090, -70 });
	}

	{
		BNormalBlock* NewActor = GetWorld()->SpawnActor<BNormalBlock>();
		NewActor->SetActorLocation({ 4552, 296});

		QBlockwithMushroom* QBlock = GetWorld()->SpawnActor<QBlockwithMushroom>();
		QBlock->SetActorLocation({ 4552, 296 });
		QBlock->SetColImage("3rdColMap.png");
		QBlock->ItsB = true;
	}
	{
		BNormalBlock* NewActor = GetWorld()->SpawnActor<BNormalBlock>();
		NewActor->SetActorLocation({ 4610, 296 });

		QBlockwithCoin* QBlock = GetWorld()->SpawnActor<QBlockwithCoin>();
		QBlock->SetActorLocation({ 4610, 296 });
	}
	{
		BNormalBlock* NewActor = GetWorld()->SpawnActor<BNormalBlock>();
		NewActor->SetActorLocation({ 4668, 296 });

		StarBox* QMark = GetWorld()->SpawnActor<StarBox>();
		QMark->SetActorLocation({ 4668, 296 });
		QMark->SetColImage("3rdColMap.png");
	}

	{
		FireBallSwitch* NewActor = GetWorld()->SpawnActor<FireBallSwitch>();
		NewActor->SetActorLocation({ 5595, 585 });
	}
	{
		ThePipe = GetWorld()->SpawnActor<FBPipe>();
		ThePipe->SetActorLocation({ 5975, 619 });
	}

	{
		FDBlock7* FDB = GetWorld()->SpawnActor<FDBlock7>();
		FDB->SetActorLocation({ 7278, 669 });
	}

	
	{
		ColPipe2* NewActor = GetWorld()->SpawnActor<ColPipe2>();
		NewActor->SetActorLocation({ 7550, 442 });
	}
	{
		ThirdMapP2* NewActor = GetWorld()->SpawnActor<ThirdMapP2>();
		NewActor->SetActorLocation({ 7550, 442 });
	}

	BGMPlayer.SetVolume(0.5f);
	BGMPlayer = UEngineSound::Play("UnderGround.MP3");

}

void GameMode_ThirdMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	ReStart(_DeltaTime);
	Clear();

	MonsterSwitch();
	MonsterShowUp();

	KWCSwitch();
	KWCShowUp();
	BearSwitch();
	BearShowUp();

	CatIsUnderTheBlock1();

	FBPSwtich();

	Stairs(_DeltaTime);
	StopTheMusic();

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_FourthMap");
	}

	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();

	if (true == UEngineInput::GetInst().IsDown(VK_F3))
	{
		Player->SetActorLocation({ 6000, 420 });
	}

}

void GameMode_ThirdMap::StopTheMusic()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	if (Player->IsCatKilled == true)
	{
		BGMPlayer.Stop();
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

	if (Player->ItsTunnel == true)
	{
		BGMPlayer.Stop();
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
		NewActor->Jump = true;
		DoItOnce1 = false;
	}
}

void GameMode_ThirdMap::BearSwitch()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	FVector2D PlayerPos = Player->GetActorLocation();
	if (3070.0f <= PlayerPos.X)
	{
		BearLever = true;
	}
}

void GameMode_ThirdMap::BearShowUp()
{
	if (BearLever == true && DoItOnce2 == true)
	{
		Bear* NewActor = GetWorld()->SpawnActor<Bear>();
		NewActor->SetActorLocation({ 3191, 500 });
		NewActor->SetColImage("3rdColMap.png");
		BearLever = false;

		DoItOnce2 = false;
	}
}

void GameMode_ThirdMap::CatIsUnderTheBlock1()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	FVector2D PlayerPos = Player->GetActorLocation();
	if (PlayerPos.X >= 4030.0f)
	{
		FDB4->IsFalling = true;
		TimeEventer.PushEvent(1.0f, std::bind(&GameMode_ThirdMap::CatIsUnderTheBlock2, this));
		TimeEventer.PushEvent(2.3f, std::bind(&GameMode_ThirdMap::CatIsUnderTheBlock3, this));
	}
}

void GameMode_ThirdMap::CatIsUnderTheBlock2()
{
	FDB5->IsFalling = true;
}

void GameMode_ThirdMap::CatIsUnderTheBlock3()
{
	FDB6->IsFalling = true;
}

void GameMode_ThirdMap::FBPSwtich()
{
	if (FireBallSwitch::Switch == true)
	{
		ThePipe->SwitchUp = true;
	}
}

void GameMode_ThirdMap::Stairs(float _DeltaTime)
{
	UpStairTimer += _DeltaTime;
	DownStairTimer += _DeltaTime;

	if (UpStairTimer > 2.5f)
	{
		{
			UpStair* TheStairU = GetWorld()->SpawnActor<UpStair>();
			TheStairU->SetActorLocation({ 6530, 850 });

			FVector2D UStairPos = TheStairU->GetActorLocation();
			if (UStairPos.Y <= -10.0f)
			{
				TheStairU->Destroy();
			}
		}
		UpStairTimer = 0.0f;
	}

	if (DownStair::Faster == true)
	{
		StairTimerValue = 0.9f;
	}
	
	if (DownStairTimer > StairTimerValue)
	{
		{
			DownStair* TheStairD = GetWorld()->SpawnActor<DownStair>();
			TheStairD->SetActorLocation({ 6780, -10 });

			FVector2D DStairPos = TheStairD->GetActorLocation();
			if (DStairPos.Y >= 850.0f)
			{
				TheStairD->Destroy();
			}
		}

		DownStairTimer = 0.0f;
	}
	
	
}

void GameMode_ThirdMap::MonsterSwitch()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
	FVector2D PlayerPos = Player->GetActorLocation();
	if (PlayerPos.X >= 1190.0f)
	{
		MonsterLever = true;
	}
}

void GameMode_ThirdMap::MonsterShowUp()
{
	if (MonsterLever == true && DoItOnce3 == true)
	{
		{
			WhiteCircle* NewActor = GetWorld()->SpawnActor<WhiteCircle>();
			NewActor->SetActorLocation({ 2057, 700 });
			NewActor->SetColImage("3rdColMap.png");
		}
		{
			WhiteCircle* NewActor = GetWorld()->SpawnActor<WhiteCircle>();
			NewActor->SetActorLocation({ 2117, 700 });
			NewActor->SetColImage("3rdColMap.png");
		}
		{
			WhiteCircle* NewActor = GetWorld()->SpawnActor<WhiteCircle>();
			NewActor->SetActorLocation({ 2177, 700 });
			NewActor->SetColImage("3rdColMap.png");
		}
		{
			Turtle* NewActor = GetWorld()->SpawnActor<Turtle>();
			NewActor->SetActorLocation({ 1830, 600 });
			NewActor->SetColImage("3rdColMap.png");
		}
		DoItOnce3 = false;
	}
}