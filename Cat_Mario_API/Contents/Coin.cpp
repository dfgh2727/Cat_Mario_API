#include "PreCompile.h"
#include "Coin.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include <EngineCore/EngineAPICore.h>

Coin::Coin()
{
	USpriteRenderer* CoinRenderer = CreateDefaultSubObject<USpriteRenderer>();
	CoinRenderer->SetSprite("Coin.png");
	CoinRenderer->SetOrder(ERenderOrder::OBJECT);
	CoinRenderer->SetComponentScale({ 35, 50 });

}

Coin::~Coin()
{
}

void Coin::BeginPlay()
{
	Super::BeginPlay();
}

void Coin::Tick(float _DeltaTime)
{
	Time = UEngineAPICore::GetCore()->GetDeltaTime();
	Super::Tick(_DeltaTime);

	RiseUp();
	Destroy(0.5f);
	
}

void Coin::RiseUp()
{
	AddActorLocation(FVector2D::UP * 0.25f);
}