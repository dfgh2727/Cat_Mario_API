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
		CollisionComponent1 = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent1->SetComponentScale({ 20, 604 });
		CollisionComponent1->SetCollisionGroup(ECollisionGroup::Prop);
		CollisionComponent1->SetCollisionType(ECollisionType::Rect);
	}
	{
		CollisionComponent2 = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent2->SetComponentScale({ 60, 60 });
		CollisionComponent2->SetCollisionGroup(ECollisionGroup::Prop);
		CollisionComponent2->SetCollisionType(ECollisionType::Rect);
		CollisionComponent2->SetComponentLocation(FVector2D{ 0, 328 });
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

	CatTouchedStaff();

	/*{

	AActor* Result = CollisionComponent1->CollisionOnce(ECollisionGroup::PlayerBody);
	if (nullptr != Result)
	{
		MarioCat* MainPlayer = GetWorld()->GetPawn<MarioCat>();
		MainPlayer->StaffTouched = true;
	}
	}*/

	{

	AActor* Result = CollisionComponent2->CollisionOnce(ECollisionGroup::PlayerFoot);
	if (nullptr != Result)
	{
		MarioCat* MainPlayer = GetWorld()->GetPawn<MarioCat>();
		MainPlayer->StaffBlockTouched = true;
	}
	}
}

void Staff::CatTouchedStaff()
{
	AActor* Result = CollisionComponent1->CollisionOnce(ECollisionGroup::PlayerBody);
	if (nullptr != Result)
	{
		MarioCat* MainPlayer = GetWorld()->GetPawn<MarioCat>();
		MainPlayer->StaffTouched = true;
	}
}
