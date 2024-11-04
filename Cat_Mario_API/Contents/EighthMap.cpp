#include "PreCompile.h"
#include "EighthMap.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "Enum.h"


EighthMap::EighthMap()
{
	USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::MAP);
	SpriteRenderer->SetSprite("8thMap.png");

	FVector2D MapScale = SpriteRenderer->SetSpriteScale(1.0f);
	SpriteRenderer->SetComponentLocation(MapScale.Half());
}


EighthMap::~EighthMap()
{
}

