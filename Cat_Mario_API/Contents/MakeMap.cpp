#include "PreCompile.h"
#include "MakeMap.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "Enum.h"


MakeMap::MakeMap()
{
	USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SpriteRenderer->SetOrder(ERenderOrder::MAP1);
	SpriteRenderer->SetSprite("1stMap.png");

	FVector2D MapScale = SpriteRenderer->SetSpriteScale(1.0f);
	SpriteRenderer->SetComponentLocation(MapScale.Half());

}

MakeMap::~MakeMap()
{
}

