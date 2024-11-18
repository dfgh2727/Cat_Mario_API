#include "PreCompile.h"
#include "WhiteCircle.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

WhiteCircle::WhiteCircle()
{
	USpriteRenderer* MonsterRenderer = CreateDefaultSubObject<USpriteRenderer>();
	MonsterRenderer->SetSprite("BNormalBlock.png");
	MonsterRenderer->SetOrder(ERenderOrder::OBJECT);
	MonsterRenderer->SetComponentScale({ 60, 60 });
}

WhiteCircle::~WhiteCircle()
{
}

void WhiteCircle::BeginPlay()
{

}

void WhiteCircle::Tick(float _DeltaTime)
{

}

