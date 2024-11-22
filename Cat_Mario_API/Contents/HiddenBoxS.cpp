#include "PreCompile.h"
#include "HiddenBoxS.h"
#include "Enum.h"
#include "Coin.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

HiddenBoxS::HiddenBoxS()
{
	SkyRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SkyRenderer->SetSprite("SkyBlock.png");
	SkyRenderer->SetOrder(ERenderOrder::BLOCK);
	SkyRenderer->SetComponentScale({ 60, 60 });

	RenderCollisionComponent();
}

HiddenBoxS::~HiddenBoxS()
{
}

void HiddenBoxS::BeginPlay()
{
	Super::BeginPlay();
}

void HiddenBoxS::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	BlockDisappear(_DeltaTime);
}
