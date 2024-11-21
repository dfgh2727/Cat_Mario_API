#include "PreCompile.h"
#include "Coin.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

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
	Super::Tick(_DeltaTime);


}