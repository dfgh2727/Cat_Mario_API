#include "PreCompile.h"
#include "FirstMapP2.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "MarioCat.h"

FirstMapP2::FirstMapP2()
{
	USpriteRenderer* FirstMapP1Renderer = CreateDefaultSubObject<USpriteRenderer>();
	FirstMapP1Renderer->SetSprite("1stMapP2.png");
	FirstMapP1Renderer->SetOrder(ERenderOrder::PIPE);
	FirstMapP1Renderer->SetComponentScale({ 120, 234 });

	{
		CollisionComponent1 = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent1->SetComponentScale({ 120, 60 });
		CollisionComponent1->SetCollisionGroup(ECollisionGroup::Prop);
		CollisionComponent1->SetCollisionType(ECollisionType::Rect);
		CollisionComponent1->SetComponentLocation(FVector2D{ 0, -87 });

	}
	{
		CollisionComponent2 = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent2->SetComponentScale({ 102, 174 });
		CollisionComponent2->SetCollisionGroup(ECollisionGroup::Prop);
		CollisionComponent2->SetCollisionType(ECollisionType::Rect);
		CollisionComponent2->SetComponentLocation(FVector2D{ 1, 30 });
	}

	DebugOn();
}

FirstMapP2::~FirstMapP2()
{
}

void FirstMapP2::BeginPlay()
{
	Super::BeginPlay();
}

void FirstMapP2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	CatInthePipe();
	PipeMotion(_DeltaTime);
}

void FirstMapP2::CatInthePipe()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();

	if (Player->InThePipe == true)
	{
		ShakeThePipe = true;
	}
}

void FirstMapP2::PipeMotion(float _DeltaTime)
{
	if (Time >= 3.0f)
	{
		ShakeThePipe = false;
		TimeEventer.PushEvent(1.0f, std::bind(&FirstMapP2::Launch, this, _DeltaTime));
	}

	if (ShakeThePipe == true)
	{
		Shake(_DeltaTime);
	}
}
void FirstMapP2::Shake(float _DeltaTime)
{
	Time += _DeltaTime;
	ShakingTime += _DeltaTime;

	if (ShakingTime <= 0.05f)
	{
		AddActorLocation(FVector2D::RIGHT * 200.0f * _DeltaTime);
	}
	else if (0.08f <= ShakingTime <= 0.14f)
	{
		AddActorLocation(FVector2D::LEFT * 350.0f * _DeltaTime);
	}
	else if (ShakingTime > 0.15f)
	{
		ShakingTime = 0.0f;
	}
}

void FirstMapP2::Launch(float _DeltaTime)
{
	AddActorLocation(FVector2D::UP * 1000.0f * _DeltaTime);
}

