#include "PreCompile.h"
#include "GameMode_TheEnd.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "EndImage.h"

GameMode_TheEnd::GameMode_TheEnd()
{
}

GameMode_TheEnd::~GameMode_TheEnd()
{
}

void GameMode_TheEnd::BeginPlay()
{
	Super::BeginPlay();

	EndImage* NewActor = GetWorld()->SpawnActor<EndImage>();
}

void GameMode_TheEnd::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		UEngineAPICore::GetCore()->OpenLevel("Title");
	}

}
