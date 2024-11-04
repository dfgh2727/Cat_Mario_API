#include "PreCompile.h"
#include "SixthMap.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "Enum.h"


SixthMap::SixthMap()
{
	USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::MAP);
	SpriteRenderer->SetSprite("6thMap.png");

	FVector2D MapScale = SpriteRenderer->SetSpriteScale(1.0f);
	SpriteRenderer->SetComponentLocation(MapScale.Half());
}


SixthMap::~SixthMap()
{
}
