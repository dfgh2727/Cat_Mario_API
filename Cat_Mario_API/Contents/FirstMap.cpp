#include "PreCompile.h"
#include "FirstMap.h"
#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "Enum.h"

#include <EnginePlatform/EngineInput.h>



FirstMap::FirstMap()
{
	{
		USpriteRenderer* BackSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		BackSpriteRenderer->SetOrder(ERenderOrder::MAP);
		BackSpriteRenderer->SetSprite("1stMap.png");

		FVector2D MapScale = BackSpriteRenderer->SetSpriteScale(1.0f);
		BackSpriteRenderer->SetComponentLocation(MapScale.Half());
	}

	{
		USpriteRenderer* ColSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		ColSpriteRenderer->SetOrder(ERenderOrder::COLLISION);
		ColSpriteRenderer->SetSprite("1stColMap.png");

		FVector2D MapScale = ColSpriteRenderer->SetSpriteScale(1.0f);
		ColSpriteRenderer->SetComponentLocation(MapScale.Half());
	}

}

FirstMap::~FirstMap()
{
}

