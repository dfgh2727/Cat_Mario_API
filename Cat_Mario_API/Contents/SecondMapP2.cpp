#include "PreCompile.h"
#include "SecondMapP2.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "MarioCat.h"

SecondMapP2::SecondMapP2()
{
	USpriteRenderer* FirstMapP1Renderer = CreateDefaultSubObject<USpriteRenderer>();
	FirstMapP1Renderer->SetSprite("1stMapP2.png");
	FirstMapP1Renderer->SetOrder(ERenderOrder::PIPE);
	FirstMapP1Renderer->SetComponentScale({ 120, 234 });
	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 102, 234 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	DebugOn();
}

SecondMapP2::~SecondMapP2()
{
}

void SecondMapP2::BeginPlay()
{
	Super::BeginPlay();

	// 물개가 나간 다음에 다음 맵으로 이동 가능함
}

void SecondMapP2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	CatCheck(_DeltaTime);
}

void SecondMapP2::CatCheck(float _DeltaTime)
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();

	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerFoot);
	if (nullptr != Result)
	{
		if (true == UEngineInput::GetInst().IsPress(VK_SPACE))
		{
			Player->OnThePipe = true;
		}
	}
}
