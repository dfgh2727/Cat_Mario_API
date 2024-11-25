#include "PreCompile.h"
#include "Turtle.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>
#include <EngineBase/EngineMath.h>
#include <EngineCore/ImageManager.h>
#include <EnginePlatform/EngineInput.h>

#include "Enum.h"
#include "GameMode_FirstMap.h"


Turtle::Turtle()
{
	{
		MonsterRenderer = CreateDefaultSubObject<USpriteRenderer>();
		MonsterRenderer->SetSprite("CMmon_Right.png");
		MonsterRenderer->SetOrder(ERenderOrder::PLAYER);
		MonsterRenderer->SetComponentScale({ 120, 120 });
	}
	{
		MonsterBody = CreateDefaultSubObject<U2DCollision>();
		MonsterBody->SetComponentScale({ 55, 53 });
		MonsterBody->SetCollisionGroup(ECollisionGroup::MonsterBody);
		MonsterBody->SetCollisionType(ECollisionType::Rect);
	}
	{
		BouncyBody = CreateDefaultSubObject<U2DCollision>();
		BouncyBody->SetComponentScale({ 55, 53 });
		BouncyBody->SetCollisionGroup(ECollisionGroup::BouncyObject);
		BouncyBody->SetCollisionType(ECollisionType::Rect);
	}

	MonsterRenderer->CreateAnimation("Turtle_RunRight", "CMmon_Right.png", 1, 1, 0.5f);
	MonsterRenderer->CreateAnimation("Turtle_RunLeft", "CMmon_Left.png", 1, 1, 0.5f);

	MonsterRenderer->ChangeAnimation("Turtle_RunLeft");

	DebugOn();
}

Turtle::~Turtle()
{
}

void Turtle::BeginPlay()
{
	Super::BeginPlay();
}

void Turtle::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Move(_DeltaTime);
	IsKilled(_DeltaTime);

	GetOutOfBox(_DeltaTime);
	RiseUp(_DeltaTime);
}

void Turtle::IsKilled(float _DeltaTime)
{

}
