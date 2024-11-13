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

#include "Enum.h"
//#include <EngineCore/2DCollision.h>

MarioCat::MarioCat()
{
	SetActorLocation({ 300, 700 });

	{
		CatRenderer = CreateDefaultSubObject<USpriteRenderer>();
		CatRenderer->SetSprite("CMPlayer_Right.png");
		CatRenderer->SetOrder(ERenderOrder::PLAYER);
		CatRenderer->SetComponentScale({ 100, 100 });

		{
			CollisionHead = CreateDefaultSubObject<U2DCollision>();
			CollisionHead->SetComponentScale({ 34, 8 });
			CollisionHead->SetCollisionGroup(ECollisionGroup::PlayerHead);
			CollisionHead->SetCollisionType(ECollisionType::Rect);
			CollisionHead->SetComponentLocation(FVector2D{ 0, -30 });
		}

		{
			CollisionFoot = CreateDefaultSubObject<U2DCollision>();
			CollisionFoot->SetComponentScale({ 34, 8 });
			CollisionFoot->SetCollisionGroup(ECollisionGroup::PlayerFoot);
			CollisionFoot->SetCollisionType(ECollisionType::Rect);
			CollisionFoot->SetComponentLocation(FVector2D{ 0, 29 });
		}

		CatRenderer->CreateAnimation("Cat_RunRight", "CMPlayer_Right.png", 0, 1, 0.25f); 
		CatRenderer->CreateAnimation("Cat_RunLeft", "CMPlayer_Left.png", 0, 1, 0.25f);
		CatRenderer->CreateAnimation("Cat_StandRight", "CMPlayer_Right.png", 0, 0, 0.5f);
		CatRenderer->CreateAnimation("Cat_StandLeft", "CMPlayer_Left.png", 0, 0, 0.5f);
		CatRenderer->CreateAnimation("Cat_JumpRight", "CMPlayer_Right.png", 2, 2, 0.5f);
		CatRenderer->CreateAnimation("Cat_JumpLeft", "CMPlayer_Left.png", 2, 2, 0.5f);

		CatRenderer->ChangeAnimation("Cat_StandRight");

	}

		DebugOn();    
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

void MarioCat::DirCheck()
{

	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))
	{
		DirString = "Right";
	}

	if (true == UEngineInput::GetInst().IsPress(VK_LEFT))
	{
		DirString = "Left";
	}

}

void MarioCat::PlayerGroundCheck(FVector2D _MovePos)
{
	IsGround = false;

	if (nullptr != ColImage)
	{
		// 픽셀충돌에서 제일 중요한건 애초에 박히지 않는것이다.
		FVector2D CatScale = CatRenderer->GetTransform().Scale;
		FVector2D NextPos = GetActorLocation() + FVector2D{ 0.0f, (CatScale.Y * 0.3f) } + _MovePos;

		NextPos.X = floorf(NextPos.X);
		NextPos.Y = floorf(NextPos.Y);

		UColor Color = ColImage->GetColor(NextPos, UColor::WHITE);
		if (Color == UColor::WHITE)
		{
			IsGround = false;
		}
		else if (Color == UColor::BLACK)
		{
			IsGround = true;
			// 땅에 박히지 않을때까지 올려주는 기능도 함께 만들거나 해야한다.
		}
	}
}

void MarioCat::Gravity(float _DeltaTime)
{
	if (false == IsGround)
	{
		// 증가시키고 
		// 여기서 계산
		AddActorLocation(GravityForce * _DeltaTime);
		GravityForce += FVector2D::DOWN * _DeltaTime * 500.0f;
	}
	else {
		GravityForce = FVector2D::ZERO;
	}

}

//void MarioCat::Friction(float _DeltaTime)
//{
//	if (false == IsGround)
//	{
//		// 증가시키고 
//		// 여기서 계산
//		AddActorLocation(FrictionCo * _DeltaTime);
//		FVector2D RunningDir = FVector2D::ZERO;
//
//		if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))
//		{
//			RunningDir = FVector2D::LEFT;
//		}
//
//		if (true == UEngineInput::GetInst().IsPress(VK_LEFT))
//		{
//			RunningDir = FVector2D::RIGHT;
//		}
//
//		FrictionCo -= RunningDir * _DeltaTime * 800.0f;
//	}
	/*else {
		
	}*/

	// 상시 
//}

void MarioCat::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	UEngineDebug::CoreOutPutString("FPS : " + std::to_string(1.0f / _DeltaTime));
	UEngineDebug::CoreOutPutString("PlayerPos : " + GetActorLocation().ToString());

	BreakTheBlock(_DeltaTime);
	StandOnIt(_DeltaTime);


	if (true == UEngineInput::GetInst().IsDown('R'))
	{
		UEngineDebug::SwitchIsDebug();
	}

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

	MainCamera();
	DirCheck();
}

void MarioCat::ChangeState(PlayerState _CurPlayerState)
{
	CurPlayerState = _CurPlayerState;
}

void MarioCat::MainCamera()
{
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

void MarioCat::Idle(float _DeltaTime)
{
	PlayerGroundCheck(GravityForce * _DeltaTime);
	Gravity(_DeltaTime);

	CatRenderer->ChangeAnimation("Cat_Stand" + DirString);

	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT) ||
		true == UEngineInput::GetInst().IsPress(VK_LEFT)  ||
		true == UEngineInput::GetInst().IsPress(VK_UP))
	{
		ChangeState(PlayerState::Move);
		return;
	}
}

void MarioCat::Move(float _DeltaTime)
{
	PlayerGroundCheck(GravityForce * _DeltaTime);
	//Friction(_DeltaTime);
	Gravity(_DeltaTime);

	FVector2D Vector = FVector2D::ZERO;

	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))
	{
		CatRenderer->ChangeAnimation("Cat_Run" + DirString);
		Vector += FVector2D::RIGHT;
	}
	if (true == UEngineInput::GetInst().IsPress(VK_LEFT))
	{
		CatRenderer->ChangeAnimation("Cat_Run" + DirString);
		Vector += FVector2D::LEFT;
	}
	AddActorLocation(Vector * _DeltaTime * Speed);
	
	if (true == UEngineInput::GetInst().IsPress(VK_UP))
	{
		CatRenderer->ChangeAnimation("Cat_Jump" + DirString);
	    AddActorLocation(JumpPower * _DeltaTime);
		return;
	}

	if (false == UEngineInput::GetInst().IsPress(VK_RIGHT) &&
		false == UEngineInput::GetInst().IsPress(VK_LEFT) &&
		false == UEngineInput::GetInst().IsPress(VK_UP))
	{
		ChangeState(PlayerState::Idle);
		return;
	}


	while (true)
	{
		UColor Color = ColImage->GetColor(GetActorLocation()+ FVector2D { 0, 29 }, UColor::WHITE);
		if (Color == UColor::BLACK)
		{
			// 나가 땅위로 올라갈때까지 while 계속 올려준다.
			AddActorLocation(FVector2D::UP);
		}
		else {
			break;
		}

	}

	UEngineDebug::CoreOutPutString("IsGround : " + std::to_string(IsGround));
	
}

void MarioCat::BreakTheBlock(float _DeltaTime)
{
	AActor* Result = CollisionHead->CollisionOnce(ECollisionGroup::SquareBlock);
	if (nullptr != Result)
	{
		Result->Destroy();
	}
}

void MarioCat::StandOnIt(float _DeltaTime)
{
	AActor* Result = CollisionFoot->CollisionOnce(ECollisionGroup::SquareBlock);
	if (nullptr != Result)
	{
		UColor Color = ColImage->GetColor(GetActorLocation(), UColor::BLACK);
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




