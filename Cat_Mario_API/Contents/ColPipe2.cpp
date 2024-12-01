#include "PreCompile.h"
#include "ColPipe2.h"

#include "Enum.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "MarioCat.h"

ColPipe2::ColPipe2()
{
	{
		CollisionComponent1 = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent1->SetComponentScale({ 60, 104 });
		CollisionComponent1->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent1->SetCollisionType(ECollisionType::Rect);
		CollisionComponent1->SetComponentLocation(FVector2D{ -40, 0 });

	}
	{
		CollisionComponent2 = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent2->SetComponentScale({ 78, 104 });
		CollisionComponent2->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent2->SetCollisionType(ECollisionType::Rect);
		CollisionComponent2->SetComponentLocation(FVector2D{ 30, 10 });

	}

	DebugOn();
}

ColPipe2::~ColPipe2()
{
}

void ColPipe2::BeginPlay()
{
	Super::BeginPlay();

	// 물개가 나간 다음에 다음 맵으로 이동 가능함
}

void ColPipe2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	CatCheck(_DeltaTime);
}


void ColPipe2::CatCheck(float _DeltaTime)
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();

	AActor* Result = CollisionComponent1->CollisionOnce(ECollisionGroup::ColPlayer);
	if (nullptr != Result)
	{
		if (true == UEngineInput::GetInst().IsDown(VK_LEFT))
		{
			Player->CatWalkIn = true;
			Player->ItsTunnel = true;
			this->Destroy();
		}
	}
} 