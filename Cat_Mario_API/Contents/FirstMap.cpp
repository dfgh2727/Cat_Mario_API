#include "PreCompile.h"
#include "FirstMap.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "Enum.h"


FirstMap::FirstMap()
{
	USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::FIRSTMAP);
	SpriteRenderer->SetSprite("1stMap.png");

	FVector2D MapScale = SpriteRenderer->SetSpriteScale(1.0f);
	SpriteRenderer->SetComponentLocation(MapScale.Half());

}

FirstMap::~FirstMap()
{
}

