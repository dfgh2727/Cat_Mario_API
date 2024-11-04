#include "PreCompile.h"

#include "ThirdMap.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "Enum.h"


ThirdMap::ThirdMap()
{
	USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::MAP);
	SpriteRenderer->SetSprite("3rdMap.png");

	FVector2D MapScale = SpriteRenderer->SetSpriteScale(1.0f);
	SpriteRenderer->SetComponentLocation(MapScale.Half());
}


ThirdMap::~ThirdMap()
{
}

