#include "PreCompile.h"
#include "MarioCat.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>

MarioCat::MarioCat()
{
	SetActorLocation({ 100, 300 });
}

MarioCat::~MarioCat()
{
}

void MarioCat::BeginPlay()
{
	Super::BeginPlay();
}

void MarioCat::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))
	{
		CatRenderer->ChangeAnimation("Cat_Run");
		AddActorLocation(FVector2D::RIGHT * _DeltaTime * Speed);
	}
	if (true == UEngineInput::GetInst().IsPress(VK_LEFT))
	{
		CatRenderer->ChangeAnimation("Cat_Run");
		AddActorLocation(FVector2D::LEFT * _DeltaTime * Speed);
	}
	if (true == UEngineInput::GetInst().IsPress(VK_DOWN))
	{
		CatRenderer->ChangeAnimation("Cat_Run");
		AddActorLocation(FVector2D::DOWN * _DeltaTime * Speed);
	}
	if (true == UEngineInput::GetInst().IsPress(VK_UP))
	{
		CatRenderer->ChangeAnimation("Cat_Run");
		AddActorLocation(FVector2D::UP * _DeltaTime * Speed);
	}

	}
}

