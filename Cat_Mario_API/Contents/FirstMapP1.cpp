#include "PreCompile.h"
#include "FirstMapP1.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>

FirstMapP1::FirstMapP1()
{
	USpriteRenderer* FirstMapP1Renderer = CreateDefaultSubObject<USpriteRenderer>();
	FirstMapP1Renderer->SetSprite("1stMapP1.png");
	FirstMapP1Renderer->SetOrder(ERenderOrder::PIPE);
	FirstMapP1Renderer->SetComponentScale({ 120, 178 });

}

FirstMapP1::~FirstMapP1()
{
}

void FirstMapP1::BeginPlay()
{
	Super::BeginPlay();
}

void FirstMapP1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

