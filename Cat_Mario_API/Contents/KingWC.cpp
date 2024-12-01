#include "PreCompile.h"
#include "KingWC.h"

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


KingWC::KingWC()
{
	{
		MonsterRenderer = CreateDefaultSubObject<USpriteRenderer>();
		MonsterRenderer->SetSprite("KingWC_Left.png");
		MonsterRenderer->SetOrder(ERenderOrder::PLAYER);
		MonsterRenderer->SetComponentScale({ 120, 120 });
	}
	{
		MonsterBody = CreateDefaultSubObject<U2DCollision>();
		MonsterBody->SetComponentScale({ 55, 53 });
		MonsterBody->SetCollisionGroup(ECollisionGroup::MonsterBody);
		MonsterBody->SetCollisionType(ECollisionType::Rect);
	}

	DebugOn();
}

KingWC::~KingWC()
{
}

void KingWC::BeginPlay()
{
	Super::BeginPlay();
}

void KingWC::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Move(_DeltaTime);
}

void KingWC::Move(float _DeltaTime)
{
	MonsterGroundCheck(GravityForce * _DeltaTime);
	if (true == OnTheBlock(_DeltaTime))
	{
		IsGround = true;
	}
	Gravity(_DeltaTime);

	FVector2D MonsterPos = this->GetActorLocation();

	TurnAround(MoveDir);
	AddActorLocation(MoveDir * 0.08f);
}

void KingWC::MonsterGroundCheck(FVector2D _MovePos)
{
	IsGround = false;

	if (nullptr != ColImage)
	{
		// �ȼ��浹���� ���� �߿��Ѱ� ���ʿ� ������ �ʴ°��̴�.
		FVector2D MonsterScale = MonsterRenderer->GetTransform().Scale;
		FVector2D NextPos = GetActorLocation() + FVector2D{ 0, 22 } + _MovePos;

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

void KingWC::Gravity(float _DeltaTime)
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

bool KingWC::OnTheBlock(float _DeltaTime)
{
	std::vector<AActor*> SteppingBlock;
	bool IsOnTheBlock = MonsterBody
		->Collision(static_cast<int>(ECollisionGroup::SquareBlock), SteppingBlock, GravityForce * _DeltaTime, 100);
	return IsOnTheBlock;
}

void KingWC::TurnAround(FVector2D _MovePos)
{
	FVector2D MonsterPos = this->GetActorLocation();

	if (nullptr != ColImage)
	{
		// �̷��� ���� ��ġ
		FVector2D NextPos = MonsterPos + FVector2D{ 28.0f * PosOrN, 0.0 } + _MovePos;

		NextPos.X = floorf(NextPos.X);
		NextPos.Y = floorf(NextPos.Y);

		UColor Color = ColImage->GetColor(NextPos, UColor::WHITE);
		if (Color == UColor::BLACK)
		{
			//�������� ���ٰ� �ȼ� �浹�� �� ���������� ���� ����
			if (MoveDir == FVector2D::LEFT)
			{
				MonsterRenderer->ChangeAnimation("KingWC_Right");
				MoveDir = FVector2D::RIGHT;
				PosOrN = 1.0f;
			}
			//���������� ���ٰ� �ȼ� �浹�� �� �������� ���� ����
			else
			{
				MonsterRenderer->ChangeAnimation("KingWC_Left");
				MoveDir = FVector2D::LEFT;
				PosOrN = -1.0f;
			}

		}

	}

	AActor* Result = MonsterBody->CollisionOnce(ECollisionGroup::SquareBlock);
	if (nullptr != Result)
	{
		if (MoveDir == FVector2D::LEFT)
		{
			MonsterRenderer->ChangeAnimation("KingWC_Right");
			MoveDir = FVector2D::RIGHT;
			PosOrN = 1.0f;
		}
		//���������� ���ٰ� �ȼ� �浹�� �� �������� ���� ����
		else
		{
			MonsterRenderer->ChangeAnimation("KingWC_Left");
			MoveDir = FVector2D::LEFT;
			PosOrN = -1.0f;
		}
	}

	//���Ͱ� ���� ���� ���� ���� ��� ���� ����
	if (MonsterPos.X <= 0.0)
	{
		MonsterRenderer->ChangeAnimation("KingWC_Right");
		MoveDir = FVector2D::RIGHT;
		PosOrN = 1.0f;
	}
}
