#include "PreCompile.h"
#include "FireBallSwitch.h"

#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include <EngineCore/EngineAPICore.h>
#include "FBPipe.h"

bool FireBallSwitch::Switch = false;

FireBallSwitch::FireBallSwitch()
{
	USpriteRenderer* SwitchRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SwitchRenderer->SetSprite("Mystery.png");
	SwitchRenderer->SetOrder(ERenderOrder::PROP);
	SwitchRenderer->SetComponentScale({ 58, 58 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 58, 58 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::Prop);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}

	DebugOn();
}

FireBallSwitch::~FireBallSwitch()
{
}

void FireBallSwitch::BeginPlay()
{
	Super::BeginPlay();
}

void FireBallSwitch::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	ThePipe = GetWorld()->GetPawn<FBPipe>();

	{
		AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerBody);
		if (nullptr != Result)
		{
			Switch = true;
			this->Destroy();
		}
	}

	{
		AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerFoot);
		if (nullptr != Result)
		{
			Switch = true;
			this->Destroy();
		}
	}

}