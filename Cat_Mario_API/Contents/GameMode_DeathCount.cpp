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
	

	{
		DeathCount* NewActor = GetWorld()->SpawnActor<DeathCount>();

	}

	{
		CountDown* NewActor = GetWorld()->SpawnActor<CountDown>();

		NewActor->SetActorLocation({420, 300});
		NewActor->SetTextSpriteName("CMnum.PNG");
		NewActor->SetOrder(ERenderOrder::UI);
		NewActor->SetTextScale({ 180, 180 });
		NewActor->SetValue(5);

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



