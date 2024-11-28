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

#include "MapActor.h"
#include "Enum.h"

bool MarioCat::IsCatDead = false;
bool MarioCat::IsCatKilled = false;
FVector2D MarioCat::StartPos = FVector2D::ZERO;


MarioCat::MarioCat()
{
	/*SetActorLocation({ 300, 700 });*/

	{
		CatRenderer = CreateDefaultSubObject<USpriteRenderer>();
		CatRenderer->SetSprite("CMPlayer_Right.png");
		CatRenderer->SetOrder(ERenderOrder::PLAYER);
		CatRenderer->SetComponentScale({ 100, 100 });

		{
			CollisionBody = CreateDefaultSubObject<U2DCollision>();
			CollisionBody->SetComponentScale({ 47, 70 });
			CollisionBody->SetCollisionGroup(ECollisionGroup::ColPlayer);
			CollisionBody->SetCollisionType(ECollisionType::Rect);
		}
		{
			CollisionHead = CreateDefaultSubObject<U2DCollision>();
			CollisionHead->SetComponentScale({ 33, 8 });
			CollisionHead->SetCollisionGroup(ECollisionGroup::PlayerHead);
			CollisionHead->SetCollisionType(ECollisionType::Rect);
			CollisionHead->SetComponentLocation(FVector2D{ 0, -30 });
		}
		{
			CollisionFoot = CreateDefaultSubObject<U2DCollision>();
			CollisionFoot->SetComponentScale({ 30, 8 });
			CollisionFoot->SetCollisionGroup(ECollisionGroup::PlayerFoot);
			CollisionFoot->SetCollisionType(ECollisionType::Rect);
			CollisionFoot->SetComponentLocation(FVector2D{ 0, 30 });
		}
		{
			CollisionBody = CreateDefaultSubObject<U2DCollision>();
			CollisionBody->SetComponentScale({ 47, 55 });
			CollisionBody->SetCollisionGroup(ECollisionGroup::PlayerBody);
			CollisionBody->SetCollisionType(ECollisionType::Rect);
		}

		CatRenderer->CreateAnimation("Cat_RunRight", "CMPlayer_Right.png", 0, 1, 0.25f); 
		CatRenderer->CreateAnimation("Cat_RunLeft", "CMPlayer_Left.png", 0, 1, 0.25f);
		CatRenderer->CreateAnimation("Cat_StandRight", "CMPlayer_Right.png", 0, 0, 0.5f);
		CatRenderer->CreateAnimation("Cat_StandLeft", "CMPlayer_Left.png", 0, 0, 0.5f);
		CatRenderer->CreateAnimation("Cat_JumpRight", "CMPlayer_Right.png", 2, 2, 0.5f);
		CatRenderer->CreateAnimation("Cat_JumpLeft", "CMPlayer_Left.png", 2, 2, 0.5f);
		CatRenderer->CreateAnimation("Cat_IsDeadLeft", "CMPlayer_Left.png", 3, 3, 0.5f);
		CatRenderer->CreateAnimation("Cat_IsDeadRight", "CMPlayer_Right.png", 3, 3, 0.5f);

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

	//BGMPlayer = UEngineSound::Play("Field.MP3");

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
	//픽셀 충돌시 겹치지 않게 이동시키는 함수
	/*if (nullptr != ColImage)*/
	{
	while (true)
	{
		UColor Color = ColImage->GetColor(GetActorLocation() + FVector2D{ 0, 29 }, UColor::WHITE);
		if (Color == UColor::BLACK)
		{
			AddActorLocation(FVector2D::UP);
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		UColor Color = ColImage->GetColor(GetActorLocation() + FVector2D{ 20, 0 }, UColor::WHITE);
		if (Color == UColor::BLACK)
		{
			AddActorLocation(FVector2D::LEFT);
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		UColor Color = ColImage->GetColor(GetActorLocation() + FVector2D{ -20, 0 }, UColor::WHITE);
		if (Color == UColor::BLACK)
		{
			AddActorLocation(FVector2D::RIGHT);
		}
		else
		{
			break;
		}
	}
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
		GravityForce += FVector2D::DOWN * _DeltaTime * 1200.0f;
	}
	else 
	{
		GravityForce = FVector2D::ZERO;
	}

}

void MarioCat::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	UEngineDebug::CoreOutPutString("FPS : " + std::to_string(1.0f / _DeltaTime));
	UEngineDebug::CoreOutPutString("PlayerPos : " + GetActorLocation().ToString());

	//추후에 브금 추가시 주석 해제 
	if (true == UEngineInput::GetInst().IsDown(VK_F3))
	{
		BGMPlayer.OnOffSwtich();
	}

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
	case PlayerState::Dead:
		RightBeforeDeath(_DeltaTime);
		break;
	case PlayerState::SlipDown:
		EndMotion1(_DeltaTime);
		break;
	case PlayerState::GoToDoor:
		EndMotion2(_DeltaTime);
		break;
	case PlayerState::Clear:
		YouCleared(_DeltaTime);
		break;
	case PlayerState::GoDown:
		PipeMotion(_DeltaTime);
		break;
	default:
		break;
	}

	MainCamera();
	DirCheck();
	DontOverlap(_DeltaTime);
	HitTheBlock(_DeltaTime);
	CatIsKilled(_DeltaTime);
	Bounce(_DeltaTime);
	SueprBounce(_DeltaTime);
	StartEndMotion();
	PipeCheck();
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

	//횡스크롤...Y는 고정
	CameraPos.Y = 0.0f;

	//맵 좌측으로 카메라 이동 불가
	if (0.0 >= CameraPos.X)
	{
		CameraPos.X = 0.0f;
	}

	//맵 우측으로 카메라 이동 불가
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
		PrevPos.Y = CameraPos.Y;
		GetWorld()->SetCameraPos(PrevPos);
	}

	// 이하 고양이 이동 제한
	{
		FVector2D CatPos = this->GetActorLocation();

		if (0.0 >= CatPos.X)
		{
			CatPos.X = 0.0f;
		}

		//고양이 좌측 움직임 제한
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

		// 맵 아래로 떨어지면 죽는다
		if (MapScale.Y <= CatPos.Y)
		{
			ChangeState(PlayerState::Dead);
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

	DirVector += -DirVector * _DeltaTime * 8.0f;

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

	if (true == UEngineInput::GetInst().IsPress(VK_UP)/* && GravityForce == FVector2D::ZERO*/)
	{
		JumpPower = FVector2D(0.0f, -750.0f);
		ChangeState(PlayerState::Jump);

		BGMPlayer.Loop(0);
		BGMPlayer = UEngineSound::Play("Jump.MP3");
		return;
	}
	
	if (false == UEngineInput::GetInst().IsPress(VK_RIGHT) &&
		false == UEngineInput::GetInst().IsPress(VK_LEFT) &&
		false == UEngineInput::GetInst().IsPress(VK_UP))
	{
		ChangeState(PlayerState::Idle);
		return;
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
	//std::vector<AActor*> SteppingBlock;
	//bool IsCatOnTheBlock = CollisionFoot
	//	->Collision(static_cast<int>(ECollisionGroup::SquareBlock), SteppingBlock, GravityForce * _DeltaTime, 5);
	//return IsCatOnTheBlock;

	AActor* Result = CollisionFoot->CollisionOnce(ECollisionGroup::SquareBlock);
	if (nullptr != Result)
	{
		bool IsCatOnTheBlock = true;
		return IsCatOnTheBlock;
	}
}

void MarioCat::HitTheBlock(float _DeltaTime)
{
	{
		std::vector<AActor*> HitTheBlockR;
		bool Hit = CollisionBody
			->Collision(static_cast<int>(ECollisionGroup::SquareBlock), HitTheBlockR, FVector2D::RIGHT, 100);
		if (true == Hit)
		{
			AddActorLocation(FVector2D::LEFT);
		}
	}


	while (true /*GetPlayerState()!= PlayerState::Jump*/)
	{
		AActor* Result = CollisionBody->CollisionOnce(ECollisionGroup::SquareBlock, FVector2D::ZERO);
		if (nullptr != Result)
		{
			JumpPower = FVector2D::ZERO;
			IsGround = true;
			GravityForce = FVector2D::ZERO;
			AddActorLocation(FVector2D::UP);
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		AActor* Result = CollisionFoot->CollisionOnce(ECollisionGroup::SquareBlock, FVector2D::ZERO);
		if (nullptr != Result)
		{
			JumpPower = FVector2D::ZERO;
			IsGround = true;
			GravityForce = FVector2D::ZERO;
			AddActorLocation(FVector2D::UP);
		}
		else 
		{
			break;
		}
	}

	// 테스트
	//{
	//	std::vector<AActor*> HitTheBlockR;
	//	bool Hit = CollisionFoot
	//		->Collision(static_cast<int>(ECollisionGroup::SquareBlock), HitTheBlockR, FVector2D::RIGHT, 100);
	//	if (true == Hit)
	//	{
	//		AddActorLocation(FVector2D::LEFT);
	//	}
	//}
	//{
	//	std::vector<AActor*> HitTheBlockL;
	//	bool Hit = CollisionFoot
	//		->Collision(static_cast<int>(ECollisionGroup::SquareBlock), HitTheBlockL, FVector2D::LEFT, 100);
	//	if (true == Hit)
	//	{
	//		AddActorLocation(FVector2D::RIGHT);
	//	}
	//}

	{
		std::vector<AActor*> HitTheBlockL;
		bool Hit = CollisionBody
			->Collision(static_cast<int>(ECollisionGroup::SquareBlock), HitTheBlockL, FVector2D::ZERO, 100);
		if (true == Hit)
		{
			AddActorLocation(FVector2D::RIGHT);
		}
	}


	{
		std::vector<AActor*> HitTheBlockL;
		bool Hit = CollisionBody
			->Collision(static_cast<int>(ECollisionGroup::SquareBlock), HitTheBlockL, FVector2D::LEFT, 100);
		if (true == Hit)
		{
			AddActorLocation(FVector2D::RIGHT);
		}
	}


	// 머리가 블럭에 닿는 순간 
	AActor* Result = CollisionHead->CollisionOnce(ECollisionGroup::SquareBlock);
	if (nullptr != Result)
	{
		ChangeState(PlayerState::Idle);
		return;
	}

}

void MarioCat::Bounce(float _DeltaTime)
{
	AActor* Result = CollisionFoot->CollisionOnce(ECollisionGroup::BouncyObject);
	if (nullptr != Result)
	{
		if (GetPlayerState() != PlayerState::Dead)
		{
			BGMPlayer.Loop(1);
			BGMPlayer = UEngineSound::Play("Bounce.MP3");

			ChangeState(PlayerState::Jump);
			GravityForce = FVector2D::ZERO;
			JumpPower = FVector2D(0.0f, -400.0f);
		}
	}
}

void MarioCat::SueprBounce(float _DeltaTime)
{
	AActor* Result = CollisionFoot->CollisionOnce(ECollisionGroup::SuperBouncyObject);
	if (nullptr != Result)
	{
		if (GetPlayerState() != PlayerState::Dead)
		{
			BGMPlayer.Loop(1);
			BGMPlayer = UEngineSound::Play("Bounce.MP3");

			ChangeState(PlayerState::Jump);
			GravityForce = FVector2D::ZERO;
			JumpPower = FVector2D(0.0f, -1000.0f);
		}
	}
}

void MarioCat::PipeCheck()
{
	if (OnThePipe == true)
	{
		ChangeState(PlayerState::GoDown);
		OnThePipe = false;
	}
}

void MarioCat::PipeMotion(float _DeltaTime)
{
	/*if (InThePipe = false)*/
	{
		CatRenderer->ChangeAnimation("Cat_JumpRight");
		AddActorLocation(FVector2D::DOWN * 100.0f * _DeltaTime);
		TimeEventer.PushEvent(0.5f, std::bind(&MarioCat::CatInThePipe, this));
	}
}

void MarioCat::CatInThePipe()
{
	InThePipe = true;
}


void MarioCat::CatIsKilled(float _DeltaTime)
{

	{
		AActor* Result = CollisionBody->CollisionOnce(ECollisionGroup::MonsterBody);
		if (nullptr != Result)
		{
			IsCatKilled = true;
			ChangeState(PlayerState::Dead);
		}
	}

	{
		AActor* Result = CollisionBody->CollisionOnce(ECollisionGroup::TurtleShell);
		if (nullptr != Result)
		{
			IsCatKilled = true;
			ChangeState(PlayerState::Dead);
		}
	}
	
}

void MarioCat::RightBeforeDeath(float _DeltaTime)
{
	CatRenderer->ChangeAnimation("Cat_IsDead" + DirString);
	TimeEventer.PushEvent(0.5f, std::bind(&MarioCat::YouDied, this, _DeltaTime));
}

void MarioCat::YouDied(float _DeltaTime)
{
	/*IsGround = true;*/
	GravityForce += FVector2D::DOWN * _DeltaTime * 1000.0f;
	AddActorLocation(GravityForce * _DeltaTime);

	CatRenderer->ChangeAnimation("Cat_IsDead" + DirString);
	FVector2D DeathMotion = FVector2D::UP * 500.0f * _DeltaTime;
	TimeEventer.PushEvent(0.5f, std::bind(&MarioCat::TurnOffTheSwitch, this));
	
	if (DeathMotionSwitch == true)
	{
		AddActorLocation(DeathMotion);
		TimeEventer.PushEvent(2.0f, std::bind(&MarioCat::DeathCheck, this));
	}
	
}

void MarioCat::TurnOffTheSwitch()
{
	DeathMotionSwitch = false;
}

void MarioCat::DeathCheck()
{
	IsCatDead = true;
}

void MarioCat::StartEndMotion()
{
	if (StaffTouched == true)
	{
		ChangeState(PlayerState::SlipDown);
		StaffTouched = false;
	}
}

void MarioCat::EndMotion1(float _DeltaTime)
{
	if (StaffBlockTouched == false)
	{
		CatRenderer->ChangeAnimation("Cat_JumpRight");
		AddActorLocation(FVector2D::DOWN * 200.0f * _DeltaTime);
	}
	if (StaffBlockTouched == true)
	{
		ChangeState(PlayerState::GoToDoor);
		StaffTouched = false;
	}
}

void MarioCat::EndMotion2(float _DeltaTime)
{
	Gravity(_DeltaTime);
	PlayerGroundCheck(GravityForce * _DeltaTime);

	CatRenderer->ChangeAnimation("Cat_RunRight");
	AddActorLocation(FVector2D::RIGHT * 150.0f * _DeltaTime);

	if (AtTheDoor == true)
	{
		ChangeState(PlayerState::Clear);
		//StaffBlockTouched = false;
	}
}

void MarioCat::YouCleared(float _DeltaTime)
{
	CatRenderer->ChangeAnimation("Cat_StandRight");
	Cleared = true;
}


void MarioCat::LevelChangeStart()
{
	Super::LevelChangeStart();

	SetActorLocation(StartPos);
}

void MarioCat::LevelChangeEnd()
{
	Super::LevelChangeEnd();
}
