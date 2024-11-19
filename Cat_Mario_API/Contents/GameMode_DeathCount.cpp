#include "PreCompile.h"
#include "GameMode_DeathCount.h"

#include <EngineCore/Level.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "DeathCount.h"
#include "MarioCat.h"
#include "CountDown.h"
#include "Enum.h"



GameMode_DeathCount::GameMode_DeathCount()
{
}

GameMode_DeathCount::~GameMode_DeathCount()
{
}

void GameMode_DeathCount::BeginPlay()
{
	DeathCounter();

	{
		DeathCount* NewActor = GetWorld()->SpawnActor<DeathCount>();

	}

	{
		CountDown* NewActor = GetWorld()->SpawnActor<CountDown>();

		NewActor->SetActorLocation({540, 420});
		NewActor->SetTextSpriteName("CMnum.PNG");
		NewActor->SetOrder(ERenderOrder::UI);
		NewActor->SetTextScale({ 128, 128 });
		NewActor->SetValue(/*Number*/11);
		// 0까지는 바로 렌더 됨... 음수는 처리한 후에 넣어야 함
	}

	if (NumberIsNegative == true)
	{

	}

}

void GameMode_DeathCount::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		UEngineAPICore::GetCore()->OpenLevel("Play_FirstMap");
	}

}

void GameMode_DeathCount::DeathCounter()
{
	Number = 2 - Count;

	if (Number < 0)
	{
		Number = Number * (-1);
		NumberIsNegative = true;
	}
	
}


