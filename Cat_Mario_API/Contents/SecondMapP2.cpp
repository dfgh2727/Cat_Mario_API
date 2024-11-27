#include "PreCompile.h"
#include "SecondMapP2.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "MarioCat.h"
#include "ColPipe.h"

SecondMapP2::SecondMapP2()
{
	USpriteRenderer* FirstMapP1Renderer = CreateDefaultSubObject<USpriteRenderer>();
	FirstMapP1Renderer->SetSprite("1stMapP2.png");
	FirstMapP1Renderer->SetOrder(ERenderOrder::PIPE);
	FirstMapP1Renderer->SetComponentScale({ 120, 234 });
}

SecondMapP2::~SecondMapP2()
{
}

void SecondMapP2::BeginPlay()
{
	Super::BeginPlay();

	// 물개가 나간 다음에 다음 맵으로 이동 가능함
}

void SecondMapP2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
