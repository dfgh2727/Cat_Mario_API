#include "PreCompile.h"
#include "MarioCat.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include <EngineBase/EngineMath.h>
#include <EngineCore/ImageManager.h>

#include "GameMode_FirstMap.h"
#include "GameMode_SecondMap.h"
#include "GameMode_ThirdMap.h"
#include "GameMode_FourthMap.h"
#include "GameMode_FifthMap.h"
#include "GameMode_SixthMap.h"
#include "GameMode_SeventhMap.h"
#include "GameMode_EighthMap.h"



MarioCat::MarioCat()
{
	SetActorLocation({ 300, 700 });

	{
		CatRenderer = CreateDefaultSubObject<USpriteRenderer>();
		CatRenderer->SetSprite("CMPlayer_Right.png");
		CatRenderer->SetComponentScale({ 100, 100 });


		CatRenderer->CreateAnimation("Cat_RunRight", "CMPlayer_Right.png", 0, 1, 0.25f); 

		CatRenderer->CreateAnimation("Cat_RunLeft", "CMPlayer_Left.png", 0, 1, 0.25f);

		CatRenderer->CreateAnimation("Cat_Stand", "CMPlayer_Right.png", 0, 0, 0.5f);

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

	switch (CurPlayerState)
	{
	case PlayerState::Idle:
		Idle(_DeltaTime);
		break;
	case PlayerState::Move:
		Move(_DeltaTime);
		break;
	default:
		break;
	}

	FVector2D Size = UEngineAPICore::GetCore()->GetMainWindow().GetWindowSize();
	GetWorld()->SetCameraPos(GetActorLocation() - Size.Half());
	FVector2D CameraPos = GetWorld()->GetCameraPos();

	CameraPos.Y = 0.0f;

	if (0.0 >= CameraPos.X)
	{
		CameraPos.X = 0.0f;
	}

	FVector2D MapScale = MapImage->GetImageScale();

	if (MapScale.X <= (Size.X + CameraPos.X))
	{
		CameraPos.X = (MapScale.X - Size.X);
	}

	GetWorld()->SetCameraPos(CameraPos);
	// GetWorld()->SetCameraPos({ 0, 0 });

	{
	   FVector2D CatPos = this->GetActorLocation();
		
		if (0.0 >= CatPos.X)
		{
			CatPos.X = 0.0f;
		}

		if (MapScale.X <= CatPos.X)
		{
			CatPos.X = MapScale.X;
		}

		if (0.0 >= CatPos.Y)
		{
			CatPos.Y = 0.0f;
		}

		if (MapScale.Y <= CatPos.Y)
		{
			CatPos.Y = MapScale.Y;
		}
		
		SetActorLocation(CatPos);
	}

}

void MarioCat::ChangeState(PlayerState _CurPlayerState)
{
	switch (_CurPlayerState)
	{
	case PlayerState::Idle:
		MarioCat::Idle(_DeltaTime);
		break;
	case PlayerState::Move:
		Move(_DeltaTime);
		break;
	default:
		break;
	}

	CurPlayerState = _CurPlayerState;

}

void MarioCat::Idle(float _DeltaTime)
{
	if (true == UEngineInput::GetInst().IsPress('A') ||
		true == UEngineInput::GetInst().IsPress('D') ||
		true == UEngineInput::GetInst().IsPress('W') ||
		true == UEngineInput::GetInst().IsPress('S'))
	{
		ChangeState(PlayerState::Move);
		return;
	}
}

void MarioCat::Move(float _DeltaTime)
{
	FVector2D Vector = FVector2D::ZERO;

	if (true == UEngineInput::GetInst().IsPress('D'))
	{
		Vector += FVector2D::RIGHT;
		CatRenderer->ChangeAnimation("Cat_RunRight");
	}
	if (true == UEngineInput::GetInst().IsPress('A'))
	{
		Vector += FVector2D::LEFT;
		CatRenderer->ChangeAnimation("Cat_RunLeft");
	}
	if (true == UEngineInput::GetInst().IsPress('S'))
	{
		Vector += FVector2D::DOWN;
		CatRenderer->ChangeAnimation("Cat_Stand");
	}
	if (true == UEngineInput::GetInst().IsPress('W'))
	{
		Vector += FVector2D::UP;
		CatRenderer->ChangeAnimation("Cat_Stand");

	}

	if (false == UEngineInput::GetInst().IsPress('A') &&
		false == UEngineInput::GetInst().IsPress('D') &&
		false == UEngineInput::GetInst().IsPress('W') &&
		false == UEngineInput::GetInst().IsPress('S'))
	{
		ChangeState(PlayerState::Idle);
		return;
	}

	if (nullptr != ColImage)
	{

		// 픽셀충돌에서 제일 중요한건 애초에 박히지 않는것이다.
		FVector2D NextPos = GetActorLocation() + Vector * _DeltaTime * Speed;

		UColor Color = ColImage->GetColor(NextPos, UColor::BLACK);
		if (Color == UColor::WHITE)
		{
			AddActorLocation(Vector * _DeltaTime * Speed);
		}
	}
}


void MarioCat::SetMapImage(std::string_view _MapImageName)
{
	MapImage = UImageManager::GetInst().FindImage(_MapImageName);
}

void MarioCat::SetColImage(std::string_view _ColImageName)
{
	ColImage = UImageManager::GetInst().FindImage(_ColImageName);
}

void MarioCat::LevelChangeStart()
{
	Super::LevelChangeStart();
}

void MarioCat::LevelChangeEnd()
{
	Super::LevelChangeEnd();
}

