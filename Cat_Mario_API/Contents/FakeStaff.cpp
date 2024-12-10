#include "PreCompile.h"
#include "FakeStaff.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "Enum.h"
#include "MarioCat.h"

FakeStaff::FakeStaff()
{
	USpriteRenderer* StaffRenderer = CreateDefaultSubObject<USpriteRenderer>();
	StaffRenderer->SetSprite("FakeStaff.png");
	StaffRenderer->SetOrder(ERenderOrder::PROP);
	StaffRenderer->SetComponentScale({ 44, 620 });

	{
		CollisionComponent1 = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent1->SetComponentScale({ 44, 42 });
		CollisionComponent1->SetCollisionGroup(ECollisionGroup::BouncyObject);
		CollisionComponent1->SetCollisionType(ECollisionType::Rect);
		CollisionComponent1->SetComponentLocation(FVector2D{ 0, -289 });

	}
	{
		CollisionComponent2 = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent2->SetComponentScale({ 20, 576 });
		CollisionComponent2->SetCollisionGroup(ECollisionGroup::MonsterBody);
		CollisionComponent2->SetCollisionType(ECollisionType::Rect);
		CollisionComponent2->SetComponentLocation(FVector2D{ 0, 20 });
	}

	DebugOn();
}

FakeStaff::~FakeStaff()
{
}

void FakeStaff::BeginPlay()
{
	Super::BeginPlay();
}

void FakeStaff::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}