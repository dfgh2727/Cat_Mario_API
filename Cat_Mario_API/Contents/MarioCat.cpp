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
	/*	{
			CollisionBody = CreateDefaultSubObject<U2DCollision>();
			CollisionBody->SetComponentScale({ 45, 40 });
			CollisionBody->SetCollisionGroup(ECollisionGroup::PlayerBody);
			CollisionBody->SetCollisionType(ECollisionType::Rect);
		}*/

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

	/*BGMPlayer = UEngineSound::Play("Field.MP3");*/

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

void MarioCat::DontOverlap(float _DeltaTime)
{

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
		GravityForce += FVector2D::DOWN * _DeltaTime * 700.0f;
	}
	else {
		GravityForce = FVector2D::ZERO;
	}

}

void MarioCat::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	UEngineDebug::CoreOutPutString("FPS : " + std::to_string(1.0f / _DeltaTime));
	UEngineDebug::CoreOutPutString("PlayerPos : " + GetActorLocation().ToString());

	//if (true == UEngineInput::GetInst().IsDown(VK_F3))
	//{
	//	BGMPlayer.OnOffSwtich();

	//	// static썼다. 
	//	//UEngineAPICore::GetCore()->ResetLevel<APlayGameMode, ANewPlayer>("Play");
	//	//UEngineAPICore::GetCore()->OpenLevel("Play");
	//}

	/*BreakTheBlock(_DeltaTime);*/

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
	case PlayerState::Jump:
		Jump(_DeltaTime);
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

	// 이전 위치보다 x가 전진했을때
	// 맨처음
	//   100         50
	if (PrevPos.X < CameraPos.X)
	{
		GetWorld()->SetCameraPos(CameraPos);
		PrevPos = CameraPos;
	}
	else 
	{
		// 
		PrevPos.Y = CameraPos.Y;
		GetWorld()->SetCameraPos(PrevPos);
	}

	{
		FVector2D CatPos = this->GetActorLocation();

		if (0.0 >= CatPos.X)
		{
			CatPos.X = 0.0f;
		}

		if (CatPos.X <= PrevPos.X)
		{
			CatPos.X = PrevPos.X;
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

	if (true == CatOnTheBlock(_DeltaTime))
	{
		IsGround = true;
	}

	Gravity(_DeltaTime);

	CatRenderer->ChangeAnimation("Cat_Stand" + DirString);

	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT) ||
		true == UEngineInput::GetInst().IsPress(VK_LEFT)  ||
		true == UEngineInput::GetInst().IsPress(VK_UP))
	{
		ChangeState(PlayerState::Move);
		return;
	}

	AddActorLocation(DirVector * _DeltaTime);

	if (DirVector.Length() >= MaxSpeed)
	{
		DirVector.Normalize();
		DirVector *= MaxSpeed;
	}

	DirVector += -DirVector * _DeltaTime * 5.0f;

	if (DirVector.Length() < MinSpeed)
	{
		DirVector = FVector2D::ZERO;
	}

}

void MarioCat::Move(float _DeltaTime)
{
	PlayerGroundCheck(GravityForce * _DeltaTime);

	if (true == CatOnTheBlock(_DeltaTime))
	{
		IsGround = true;
	}

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

	DirVector += Vector * DirAcc * _DeltaTime;

	AddActorLocation(DirVector * _DeltaTime);

	if (DirVector.Length() >= MaxSpeed)
	{
		DirVector.Normalize();
		DirVector *= 300.0f;
	}

	DirVector += -DirVector *_DeltaTime ;

	if (true == UEngineInput::GetInst().IsPress(VK_UP))
	{
		ChangeState(PlayerState::Jump);
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
			AddActorLocation(FVector2D::UP);
		}
		else 
		{
			break;
		}
	}

	UEngineDebug::CoreOutPutString("IsGround : " + std::to_string(IsGround));
}

void MarioCat::Jump(float _DeltaTime)
{
	AddActorLocation(JumpPower * _DeltaTime);
	Gravity(_DeltaTime);
	PlayerGroundCheck(GravityForce * _DeltaTime);
	CatRenderer->ChangeAnimation("Cat_Jump" + DirString);
	
	FVector2D Vector = FVector2D::ZERO;
	if (true == IsGround)
	{
		ChangeState(PlayerState::Idle);
		return;
	}

	if (true == CatOnTheBlock(_DeltaTime))
	{
		ChangeState(PlayerState::Idle);
	}

	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))
	{
		Vector += FVector2D::RIGHT;
	}
	if (true == UEngineInput::GetInst().IsPress(VK_LEFT))
	{
		Vector += FVector2D::LEFT;
	}

	DirVector += Vector * DirAcc * _DeltaTime;
	AddActorLocation(DirVector * _DeltaTime);
}

bool MarioCat::CatOnTheBlock(float _DeltaTime)
{
	std::vector<AActor*> SteppingBlock;
	bool IsCatOnTheBlock = CollisionFoot
		->Collision(static_cast<int>(ECollisionGroup::SquareBlock), SteppingBlock, GravityForce * _DeltaTime, 100);
	return IsCatOnTheBlock;
}

//void MarioCat::BreakTheBlock(float _DeltaTime)
//{
//}

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




