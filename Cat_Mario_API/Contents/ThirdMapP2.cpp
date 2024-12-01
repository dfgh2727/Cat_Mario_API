#include "PreCompile.h"
#include "ThirdMapP2.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "MarioCat.h"
#include "ColPipe.h"

ThirdMapP2::ThirdMapP2()
{
	USpriteRenderer* FirstMapP1Renderer = CreateDefaultSubObject<USpriteRenderer>();
	FirstMapP1Renderer->SetSprite("2ndMapP1.png");
	FirstMapP1Renderer->SetOrder(ERenderOrder::PIPE);
	FirstMapP1Renderer->SetComponentScale({ 138, 116 });
}

ThirdMapP2::~ThirdMapP2()
{
}

void ThirdMapP2::BeginPlay()
{
	Super::BeginPlay();
}

void ThirdMapP2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}
