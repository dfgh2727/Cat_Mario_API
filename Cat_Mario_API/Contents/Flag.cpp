#include "PreCompile.h"
#include "Flag.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "MarioCat.h"

Flag::Flag()
{
	USpriteRenderer* FlagRenderer = CreateDefaultSubObject<USpriteRenderer>();
	FlagRenderer->SetSprite("Flag.png");
	FlagRenderer->SetOrder(ERenderOrder::PROP);
	FlagRenderer->SetComponentScale({ 79, 120 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 65, 100 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::Prop);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
		DebugOn();
}

Flag::~Flag()
{
}

void Flag::BeginPlay()
{
	Super::BeginPlay();
}

void Flag::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerBody);
	if (nullptr != Result)
	{
		MarioCat::StartPos = GetActorLocation();
		this->Destroy();
	}

}