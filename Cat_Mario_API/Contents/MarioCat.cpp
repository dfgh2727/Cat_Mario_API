#include "PreCompile.h"
#include "MarioCat.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include <EngineBase/EngineMath.h>



MarioCat::MarioCat()
{
	SetActorLocation({ 480, 420 });

	{
		CatRenderer = CreateDefaultSubObject<USpriteRenderer>();
		CatRenderer->SetSprite("CMPlayer_Right.png");
		CatRenderer->SetComponentScale({ 100, 100 });


		CatRenderer->CreateAnimation("Cat_RunRight", "CMPlayer_Right.png", 0, 1, 0.1f);

		CatRenderer->CreateAnimation("Cat_RunLeft", "CMPlayer_Left.png", 0, 1, 0.1f);

		CatRenderer->CreateAnimation("Cat_Stand", "CMPlayer_Right.png", 0, 0, 0.1f);

		CatRenderer->ChangeAnimation("Cat_Stand");
	}
}

MarioCat::~MarioCat()
{
}

void MarioCat::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->SetCameraToMainPawn(false);

	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPivot(Size.Half() * -1.0f);
}

void MarioCat::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	UEngineDebug::CoreOutPutString("FPS : " + std::to_string(1.0f / _DeltaTime));
	UEngineDebug::CoreOutPutString("PlayerPos : " + GetActorLocation().ToString());

	//if (true == UEngineInput::GetInst().IsDown('R'))
	//{
	//	UEngineAPICore::GetCore()->OpenLevel("Title");
	//	// UEngineDebug::SwitchIsDebug();
	//}


	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))
	{
		CatRenderer->ChangeAnimation("Cat_RunRight");
		AddActorLocation(FVector2D::RIGHT * _DeltaTime * Speed);
	}
	if (true == UEngineInput::GetInst().IsPress(VK_LEFT))
	{
		CatRenderer->ChangeAnimation("Cat_RunLeft");
		AddActorLocation(FVector2D::LEFT * _DeltaTime * Speed);
	}
	if (true == UEngineInput::GetInst().IsPress(VK_DOWN))
	{
		CatRenderer->ChangeAnimation("Cat_Stand");
		AddActorLocation(FVector2D::DOWN * _DeltaTime * Speed);
	}
	if (true == UEngineInput::GetInst().IsPress(VK_UP))
	{
		CatRenderer->ChangeAnimation("Cat_RunRight");
		AddActorLocation(FVector2D::UP * _DeltaTime * Speed);
	}


	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPos(GetActorLocation() - Size.Half());
	FVector2D CameraPos = GetWorld()->GetCameraPos();

	if (0.0 >= CameraPos.X)
	{
		CameraPos.X = 0.0f;
	}

	if (0.0 >= CameraPos.Y)
	{
		CameraPos.Y = 0.0f;
	}

	if (840.0 < CameraPos.Y + Size.Y)
	{
	
	}

	GetWorld()->SetCameraPos(CameraPos);




	// GetWorld()->SetCameraPos({ 0, 0 });

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

