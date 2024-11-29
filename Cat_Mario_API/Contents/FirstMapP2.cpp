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
	Shake(_DeltaTime);

}

void FirstMapP2::CatInthePipe()
{
	MarioCat* Player = GetWorld()->GetPawn<MarioCat>();

	if (Player->InThePipe == true)
	{
		ShakeThePipe = true;
	}
}

void FirstMapP2::Shake(float _DeltaTime)
{
	if (ShakeThePipe == true)
	{
		Time += _DeltaTime;

		if (Time <= 0.05f)
		{
			AddActorLocation(FVector2D::RIGHT * 50.0f * _DeltaTime);
		}
		else if (0.08f <= Time <= 0.14f)
		{
			AddActorLocation(FVector2D::LEFT * 85.0f * _DeltaTime);
		}
		else if (Time > 0.15f)
		{
			Time = 0.0f;
		}
	}
}
