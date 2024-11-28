#include "PreCompile.h"
#include "FBPipe.h"

#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineBase/EngineRandom.h>

#include "FireBall.h"

FBPipe::FBPipe()
{
	USpriteRenderer* FirstMapP1Renderer = CreateDefaultSubObject<USpriteRenderer>();
	FirstMapP1Renderer->SetSprite("1stMapP2.png");
	FirstMapP1Renderer->SetOrder(ERenderOrder::PIPE);
	FirstMapP1Renderer->SetComponentScale({ 120, 234 });
}

FBPipe::~FBPipe()
{
}

void FBPipe::BeginPlay()
{
	Super::BeginPlay();
}

void FBPipe::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void FBPipe::ShootFB(float _DeltaTime)
{

}


