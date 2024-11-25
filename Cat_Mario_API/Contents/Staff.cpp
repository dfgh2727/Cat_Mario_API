#include "PreCompile.h"
#include "Staff.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "Enum.h"
#include "MarioCat.h"

Staff::Staff()
{
	USpriteRenderer* StaffRenderer = CreateDefaultSubObject<USpriteRenderer>();
	StaffRenderer->SetSprite("Staff.png");
	StaffRenderer->SetOrder(ERenderOrder::PROP);
	StaffRenderer->SetComponentScale({ 44, 604 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 44, 604 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::Prop);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}

	DebugOn();
}

Staff::~Staff()
{
}

void Staff::BeginPlay()
{
	Super::BeginPlay();
}

void Staff::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerBody);
	if (nullptr != Result)
	{
		MarioCat* MainPlayer = GetWorld()->GetPawn<MarioCat>();
		/*MainPlayer->*/
		this->Destroy();
	}

}

