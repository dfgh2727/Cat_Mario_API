#include "PreCompile.h"
#include "MarioCat.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>


MarioCat::MarioCat()
{
	SetActorLocation({ 480, 420 });
	
	{
		CatRenderer = CreateDefaultSubObject<USpriteRenderer>();
		CatRenderer->SetSprite("CMPlayer.png");
		CatRenderer->SetComponentScale({ 250, 250 });


		CatRenderer->CreateAnimation("Cat_Run", "CMPlayer.png", 0, 1, 0.1f);

		CatRenderer->CreateAnimation("Cat_Stand", "CMPlayer.png", 0, 0, 0.1f);

		CatRenderer->ChangeAnimation("Cat_Stand");
	}
}

MarioCat::~MarioCat()
{
}

void MarioCat::BeginPlay()
{
	Super::BeginPlay();

	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPivot(Size.Half() * -1.0f);
}

void MarioCat::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	UEngineDebug::CoreOutPutString("FPS : " + std::to_string(1.0f / _DeltaTime));
	UEngineDebug::CoreOutPutString("PlayerPos : " + GetActorLocation().ToString());

	if (true == UEngineInput::GetInst().IsDown('R'))
	{
		UEngineAPICore::GetCore()->OpenLevel("Title");
		// UEngineDebug::SwitchIsDebug();
	}


	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))
	{
		CatRenderer->ChangeAnimation("Cat_Run");
		AddActorLocation(FVector2D::RIGHT * _DeltaTime * Speed);
	}
	if (true == UEngineInput::GetInst().IsPress(VK_LEFT))
	{
		CatRenderer->ChangeAnimation("Cat_Run");
		AddActorLocation(FVector2D::LEFT * _DeltaTime * Speed);
	}
	if (true == UEngineInput::GetInst().IsPress(VK_DOWN))
	{
		CatRenderer->ChangeAnimation("Cat_Run");
		AddActorLocation(FVector2D::DOWN * _DeltaTime * Speed);
	}
	if (true == UEngineInput::GetInst().IsPress(VK_UP))
	{
		CatRenderer->ChangeAnimation("Cat_Run");
		AddActorLocation(FVector2D::UP * _DeltaTime * Speed);
	}


if (false == UEngineInput::GetInst().IsPress(VK_RIGHT) &&
	false == UEngineInput::GetInst().IsPress(VK_LEFT) &&
	false == UEngineInput::GetInst().IsPress(VK_DOWN) &&
	false == UEngineInput::GetInst().IsPress(VK_UP))
{
	CatRenderer->ChangeAnimation("Cat_Stand");
}

}

void MarioCat::LevelChangeStart() 
{
	Super::LevelChangeStart();
}

void MarioCat::LevelChangeEnd()
{
	Super::LevelChangeEnd();
}

