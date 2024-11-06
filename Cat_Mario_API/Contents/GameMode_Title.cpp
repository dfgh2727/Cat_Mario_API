#include "PreCompile.h"
#include "GameMode_Title.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineAPICore.h>

#include "TitleImage.h"

GameMode_Title::GameMode_Title()
{
}

GameMode_Title::~GameMode_Title()
{
}

void GameMode_Title::BeginPlay()
{
	Super::BeginPlay();

	TitleImage* NewActor = GetWorld()->SpawnActor<TitleImage>();
}

void GameMode_Title::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsDown(VK_SPACE))
	{
		UEngineAPICore::GetCore()->OpenLevel("DeathCount");
	}

}
