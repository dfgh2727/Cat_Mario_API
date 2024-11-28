#include "PreCompile.h"
#include "FireBallSwitch.h"

#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include <EngineCore/EngineAPICore.h>
#include "FBPipe.h"

FireBallSwitch::FireBallSwitch()
{
	USpriteRenderer* SwitchRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SwitchRenderer->SetSprite("Mystery.png");
	SwitchRenderer->SetOrder(ERenderOrder::PROP);
	SwitchRenderer->SetComponentScale({ 58, 58 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 65, 100 });
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
	{
		AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerBody);
		if (nullptr != Result)
		{
			this->Destroy();
		}
	}

	//{
	//	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead);
	//	if (nullptr != Result)
	//	{
	//		this->Destroy();
	//	}
	//}

	{
		AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerFoot);
		if (nullptr != Result)
		{
			this->Destroy();
		}
	}

}