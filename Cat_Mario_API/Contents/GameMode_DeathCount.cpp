#include "PreCompile.h"
#include "GameMode_DeathCount.h"

#include <EngineCore/Level.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "DeathCount.h"
#include "MarioCat.h"
#include "CountDown.h"
#include "Enum.h"


int GameMode_DeathCount::Number = 2;

GameMode_DeathCount::GameMode_DeathCount()
{
}

GameMode_DeathCount::~GameMode_DeathCount()
{
}

void GameMode_DeathCount::BeginPlay()
{
	Super::BeginPlay();

	{
		DeathCount* NewActor = GetWorld()->SpawnActor<DeathCount>();
	}

	{
		Counter = GetWorld()->SpawnActor<CountDown>();
		if (NumberIsNegative == true)
		{
			Counter->ShowMinus();
		}
		Counter->SetActorLocation({540, 420});
		Counter->SetTextSpriteName("CMnum.PNG");
		Counter->SetOrder(ERenderOrder::UI);
		Counter->SetTextScale({ 25, 50 });
		Counter->SetValue(Number);
	}


}

void GameMode_DeathCount::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	DeathCounter();

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_FirstMap");
	}

}

void GameMode_DeathCount::DeathCounter()
{
	/*--Number;*/

	Counter->SetValue(Number);
}


