#include "PreCompile.h"
#include "MBwithCoin.h"
#include "Coin.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>


MBwithCoin::MBwithCoin()
{
	RenderQBlock();
}

MBwithCoin::~MBwithCoin()
{
}

void MBwithCoin::BeginPlay()
{
	Super::BeginPlay();
}

void MBwithCoin::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	BlockDisappear();
}

void MBwithCoin::Show()
{
	FVector2D PresentPos = this->GetActorLocation();
	Coin* TheCoin = GetWorld()->SpawnActor<Coin>();
	TheCoin->SetActorLocation(PresentPos);
}

