#include "PreCompile.h"
#include "InfiniteCoinBox.h"
#include "Enum.h"
#include "BNormalBlock.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>
#include"MarioCat.h"

InfiniteCoinBox::InfiniteCoinBox()
{
}

InfiniteCoinBox::~InfiniteCoinBox()
{
}

void InfiniteCoinBox::BeginPlay()
{
	Super::BeginPlay();
}

void InfiniteCoinBox::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void InfiniteCoinBox::BlockDisappear(float _DeltaTime)
{
	MarioCat* MainActor = GetWorld()->GetPawn<MarioCat>();
	FVector2D GForce = MainActor->GetGravityForce();
	FVector2D CatJumpPower = MainActor->GetJumpPower();

	if (CatJumpPower.Y * (-1.0f) >= GForce.Y)
	{
		AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead);
		if (nullptr != Result)
		{
			CoinShowUP();
			this->Destroy();
		}

	}
}