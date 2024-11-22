#include "PreCompile.h"
#include "QBlockwithCoin.h"
#include "Enum.h"
#include "Coin.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>


QBlockwithCoin::QBlockwithCoin()
{
	QBlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	QBlockRenderer->SetSprite("QBlock.png");
	QBlockRenderer->SetOrder(ERenderOrder::BLOCK);
	QBlockRenderer->SetComponentScale({ 60, 60 });

	RenderCollisionComponent();
}

QBlockwithCoin::~QBlockwithCoin()
{
}

void QBlockwithCoin::BeginPlay()
{
	Super::BeginPlay();
}

void QBlockwithCoin::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	BlockDisappear(_DeltaTime);
}



