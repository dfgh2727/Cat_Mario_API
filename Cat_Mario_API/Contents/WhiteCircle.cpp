#include "PreCompile.h"

#include "WhiteCircle.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>

#include <EngineCore/Level.h>
#include <EngineBase/EngineMath.h>
#include <EngineCore/ImageManager.h>

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

	MonsterRenderer->CreateAnimation("Mon_RunRight", "CMmon_Right.png", 0, 0, 0.5f);
	MonsterRenderer->CreateAnimation("Mon_RunLeft", "CMmon_Left.png", 0, 0, 0.5f);

	MonsterRenderer->ChangeAnimation("Mon_RunLeft");

}

WhiteCircle::~WhiteCircle()
{
}

void WhiteCircle::BeginPlay()
{

}

void WhiteCircle::Tick(float _DeltaTime)
{

}

void WhiteCircle::Move(float _DeltaTime)
{

}

void WhiteCircle::MonsterGroundCheck(FVector2D _MovePos)
{
	IsGround = false;

	if (nullptr != ColImage)
	{
		// 픽셀충돌에서 제일 중요한건 애초에 박히지 않는것이다.
		FVector2D CatScale = MonsterRenderer->GetTransform().Scale;
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
}

void WhiteCircle::Gravity(float _DeltaTime)
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
