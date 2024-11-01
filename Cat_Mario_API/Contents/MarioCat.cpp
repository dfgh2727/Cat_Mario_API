#include "PreCompile.h"
#include "MarioCat.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>

MarioCat::MarioCat()
{
	SetActorLocation({ 100, 300 });
	
	{
		CatRenderer = CreateDefaultSubObject<USpriteRenderer>();
		CatRenderer->SetSprite("CMPlayer.png");
		CatRenderer->SetComponentScale({ 300, 300 });


		CatRenderer->CreateAnimation("Cat_Run", "CMPlayer.png", 0, 1, 0.1f);

		CatRenderer->CreateAnimation("Cat_Stand", "CMPlayer.png", 0, 0, 0.1f);

		CatRenderer->ChangeAnimation("Cat_Stand");
	}
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


if (false == UEngineInput::GetInst().IsPress('A') &&
	false == UEngineInput::GetInst().IsPress('D') &&
	false == UEngineInput::GetInst().IsPress('W') &&
	false == UEngineInput::GetInst().IsPress('S'))
{
	CatRenderer->ChangeAnimation("Cat_Stand");
}

}

