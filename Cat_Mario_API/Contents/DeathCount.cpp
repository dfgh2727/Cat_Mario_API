#include "PreCompile.h"
#include "DeathCount.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>

DeathCount::DeathCount()
{
	USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	/*SpriteRenderer->SetOrder(ERenderOrder::MAP);*/
	SpriteRenderer->SetSprite("DeathCount.png");

	FVector2D MapScale = SpriteRenderer->SetSpriteScale(1.0f);
	SpriteRenderer->SetComponentLocation(MapScale.Half());
}

DeathCount::~DeathCount()
{
}

