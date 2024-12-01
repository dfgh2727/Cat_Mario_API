#include "PreCompile.h"
#include "SecondMapP1.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "MarioCat.h"

SecondMapP1::SecondMapP1()
{
	USpriteRenderer* FirstMapP1Renderer = CreateDefaultSubObject<USpriteRenderer>();
	FirstMapP1Renderer->SetSprite("2ndMapP1.png");
	FirstMapP1Renderer->SetOrder(ERenderOrder::PIPE);
	FirstMapP1Renderer->SetComponentScale({ 138, 116 });

	{
		CollisionComponent1 = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent1->SetComponentScale({ 60, 104 });
		CollisionComponent1->SetCollisionGroup(ECollisionGroup::Prop);
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

SecondMapP1::~SecondMapP1()
{
}

void SecondMapP1::BeginPlay()
{
	Super::BeginPlay();
}

void SecondMapP1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AActor* Result = CollisionComponent1->CollisionOnce(ECollisionGroup::ColPlayer);
	if (nullptr != Result)
	{
		if (true == UEngineInput::GetInst().IsPress(VK_LEFT))
		{
			MarioCat* Player = GetWorld()->GetPawn<MarioCat>();
			Player->CatWalkIn = true;
		}
	}
}


