#include "PreCompile.h"
#include "FBPipe.h"

#include "Enum.h"

#include <EngineCore/Level.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineBase/EngineRandom.h>

#include "FireBall.h"

FBPipe::FBPipe()
{
	USpriteRenderer* FirstMapP1Renderer = CreateDefaultSubObject<USpriteRenderer>();
	FirstMapP1Renderer->SetSprite("1stMapP2.png");
	FirstMapP1Renderer->SetOrder(ERenderOrder::PIPE);
	FirstMapP1Renderer->SetComponentScale({ 120, 234 });

	//{
	//	CollisionComponent = CreateDefaultSubObject<U2DCollision>();
	//	CollisionComponent->SetComponentScale({ 100, 234 });
	//	CollisionComponent->SetCollisionGroup(ECollisionGroup::Prop);
	//	CollisionComponent->SetCollisionType(ECollisionType::Rect);
	//}
	//DebugOn();
}

FBPipe::~FBPipe()
{
}

void FBPipe::BeginPlay()
{
	Super::BeginPlay();
}

void FBPipe::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (SwitchUp == false)
	{
		ShootFB1(_DeltaTime);
	}
	else
	{
		ShootFB2(_DeltaTime);
	}
	
}

void FBPipe::ShootFB1(float _DeltaTime)
{
	time += _DeltaTime;

	if (time > 2.0f)
	{
		FVector2D PipePos = this->GetActorLocation();
		FireBall* FB = GetWorld()->SpawnActor<FireBall>();
		FB->SetActorLocation(PipePos);

		time = 0.0f;
	}
}

void FBPipe::ShootFB2(float _DeltaTime)
{
	time += _DeltaTime;

	if (time > 0.1f)
	{
		FVector2D PipePos = this->GetActorLocation();
		FireBall* FB = GetWorld()->SpawnActor<FireBall>();
		FB->SetActorLocation(PipePos);

		time = 0.0f;
	}
}

