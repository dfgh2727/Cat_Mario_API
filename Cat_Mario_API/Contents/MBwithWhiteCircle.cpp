#include "PreCompile.h"
#include "MBwithWhiteCircle.h"
#include "WhiteCircle.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

MBwithWhiteCircle::MBwithWhiteCircle()
{
	RenderQBlock();
}

MBwithWhiteCircle::~MBwithWhiteCircle()
{
}

void MBwithWhiteCircle::BeginPlay()
{
	Super::BeginPlay();
}

void MBwithWhiteCircle::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	BlockDisappear();
}

void MBwithWhiteCircle::Show()
{
	FVector2D PresentPos = this->GetActorLocation();
	WhiteCircle* Monster = GetWorld()->SpawnActor<WhiteCircle>();
	Monster->SetActorLocation(PresentPos);
	Monster->AddActorLocation(FVector2D::UP * 0.25f);
}


