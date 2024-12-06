#include "PreCompile.h"
#include "DownStair.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "Enum.h"

bool DownStair::Faster = false;

DownStair::DownStair()
{
	USpriteRenderer* DownStairRenderer = CreateDefaultSubObject<USpriteRenderer>();
	DownStairRenderer->SetSprite("FlyingStick.png");
	DownStairRenderer->SetOrder(ERenderOrder::PROP);
	DownStairRenderer->SetComponentScale({ 200, 20 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 200, 20 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
}

DownStair::~DownStair()
{
}

void DownStair::BeginPlay()
{
	Super::BeginPlay();
}

void DownStair::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	GoFaster();

	if (Faster == false)
	{
		AddActorLocation(FVector2D::DOWN * 100.0f * _DeltaTime);
	}
	else if (Faster == true)
	{
		AddActorLocation(FVector2D::DOWN * 250.0f * _DeltaTime);
	}
	
}

void DownStair::GoFaster()
{
	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::ColPlayer);
	if (nullptr != Result)
	{
		Faster = true;
	}
}
