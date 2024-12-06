#include "PreCompile.h"
#include "BigWC.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>
#include <EngineBase/EngineMath.h>
#include <EngineCore/ImageManager.h>
#include <EnginePlatform/EngineInput.h>

#include "MapActor.h"

#include "GameMode_FirstMap.h"
#include "Enum.h"
#include "MarioCat.h"


BigWC::BigWC()
{
	{
		MonsterRenderer = CreateDefaultSubObject<USpriteRenderer>();
		MonsterRenderer->SetSprite("BigWC.png");
		MonsterRenderer->SetOrder(ERenderOrder::PLAYER);
		MonsterRenderer->SetComponentScale({ 126, 106 });
	}
	{
		MonsterBody = CreateDefaultSubObject<U2DCollision>();
		MonsterBody->SetComponentScale({ 126, 106 });
		MonsterBody->SetCollisionGroup(ECollisionGroup::MonsterBody);
		MonsterBody->SetCollisionType(ECollisionType::Rect);
	}
	{
		BouncyBody = CreateDefaultSubObject<U2DCollision>();
		BouncyBody->SetComponentScale({ 126, 106 });
		BouncyBody->SetCollisionGroup(ECollisionGroup::BigBody);
		BouncyBody->SetCollisionType(ECollisionType::Rect);
	}

	DebugOn();
}

BigWC::~BigWC()
{
}

void BigWC::BeginPlay()
{
	Super::BeginPlay();
}

void BigWC::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Move(_DeltaTime);
}

void BigWC::Move(float _DeltaTime)
{
	MonsterGroundCheck(GravityForce * _DeltaTime);
	//if (true == OnTheBlock(_DeltaTime))
	//{
	//	IsGround = true;
	//}
	Gravity(_DeltaTime);

	FVector2D MonsterPos = this->GetActorLocation();

	AddActorLocation(MoveDir * 0.08f);
}

void BigWC::MonsterGroundCheck(FVector2D _MovePos)
{
	IsGround = false;

	if (nullptr != ColImage)
	{
		// 픽셀충돌에서 제일 중요한건 애초에 박히지 않는것이다.
		FVector2D MonsterScale = MonsterRenderer->GetTransform().Scale;
		FVector2D NextPos = GetActorLocation() + FVector2D{ 0, 53 } + _MovePos;

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

	while (true)
	{
		UColor Color = ColImage->GetColor(GetActorLocation(), UColor::WHITE);
		if (Color == UColor::BLACK)
		{
			AddActorLocation(FVector2D::UP);
		}
		else
		{
			break;
		}
	}
}

void BigWC::Gravity(float _DeltaTime)
{
	if (false == IsGround)
	{
		AddActorLocation(GravityForce * _DeltaTime);
		GravityForce += FVector2D::DOWN * _DeltaTime * 1200.0f;
	}
	else
	{
		GravityForce = FVector2D::ZERO;
	}

}

//bool BigWC::OnTheBlock(float _DeltaTime)
//{
//	std::vector<AActor*> SteppingBlock;
//	bool IsOnTheBlock = MonsterBody
//		->Collision(static_cast<int>(ECollisionGroup::SquareBlock), SteppingBlock, GravityForce * _DeltaTime, 100);
//	return IsOnTheBlock;
//}

