#include "PreCompile.h"
#include "WhiteCircle.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>
#include <EngineBase/EngineMath.h>
#include <EngineCore/ImageManager.h>

#include "MapActor.h"

#include "GameMode_FirstMap.h"
#include "Enum.h"


WhiteCircle::WhiteCircle()
{
	{
		MonsterRenderer = CreateDefaultSubObject<USpriteRenderer>();
		MonsterRenderer->SetSprite("CMmon_Right.png");
		MonsterRenderer->SetOrder(ERenderOrder::PLAYER);
		MonsterRenderer->SetComponentScale({ 120, 120 });
	}
	{
		MonsterBody = CreateDefaultSubObject<U2DCollision>();
		MonsterBody->SetComponentScale({ 60, 60 });
		MonsterBody->SetCollisionGroup(ECollisionGroup::MonsterBody);
		MonsterBody->SetCollisionType(ECollisionType::Rect);
	}

	MonsterRenderer->CreateAnimation("Mon_RunRight", "CMmon_Right.png", 0, 0, 0.5f);
	MonsterRenderer->CreateAnimation("Mon_RunLeft", "CMmon_Left.png", 0, 0, 0.5f);

	MonsterRenderer->ChangeAnimation("Mon_RunLeft");

	DebugOn();
}

WhiteCircle::~WhiteCircle()
{
}

void WhiteCircle::BeginPlay()
{

}

void WhiteCircle::Tick(float _DeltaTime)
{
	Move(_DeltaTime);
}

void WhiteCircle::Move(float _DeltaTime)
{
	MonsterGroundCheck(GravityForce * _DeltaTime);
	if (true == OnTheBlock(_DeltaTime))
	{
		IsGround = true;
	}
	Gravity(_DeltaTime);
}

void WhiteCircle::MonsterGroundCheck(FVector2D _MovePos)
{
	IsGround = false;
	ColImage = AMapActor::SetColImage(_)

	if (nullptr != ColImage)
	{
		// 픽셀충돌에서 제일 중요한건 애초에 박히지 않는것이다.
		FVector2D MonsterScale = MonsterRenderer->GetTransform().Scale;
		FVector2D NextPos = GetActorLocation() + _MovePos;

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

void WhiteCircle::Gravity(float _DeltaTime)
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

bool WhiteCircle::OnTheBlock(float _DeltaTime)
{
	std::vector<AActor*> SteppingBlock;
	bool IsOnTheBlock = MonsterBody
		->Collision(static_cast<int>(ECollisionGroup::SquareBlock), SteppingBlock, GravityForce * _DeltaTime, 100);
	return IsOnTheBlock;
}

//void WhiteCircle::SetColImage(std::string_view _ColImageName)
//{
//	ColImage = UImageManager::GetInst().FindImage(_ColImageName);
//}