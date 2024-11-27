#include "PreCompile.h"
#include "ColPipe.h"

#include "Enum.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "MarioCat.h"

ColPipe::ColPipe()
{
	{
		CollisionComponent1 = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent1->SetComponentScale({ 120, 60 });
		CollisionComponent1->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent1->SetCollisionType(ECollisionType::Rect);
		CollisionComponent1->SetComponentLocation(FVector2D{ 0, -87 });

	}
	{
		CollisionComponent2 = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent2->SetComponentScale({ 102, 174 });
		CollisionComponent2->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent2->SetCollisionType(ECollisionType::Rect);
		CollisionComponent2->SetComponentLocation(FVector2D{ 1, 30 });
	}

	DebugOn();
}

ColPipe::~ColPipe()
{
}

void ColPipe::BeginPlay()
{
	Super::BeginPlay();

	// 물개가 나간 다음에 다음 맵으로 이동 가능함
}

void ColPipe::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	CatCheck(_DeltaTime);
}


void ColPipe::CatCheck(float _DeltaTime)
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();

	AActor* Result = CollisionComponent1->CollisionOnce(ECollisionGroup::PlayerFoot);
	if (nullptr != Result)
	{
		if (true == UEngineInput::GetInst().IsDown(VK_DOWN))
		{
			Player->OnThePipe = true;
			this->Destroy();
		}
	}
}