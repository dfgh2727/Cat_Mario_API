#include "PreCompile.h"
#include "SeventhMap.h"

#include <EngineCore/EngineAPICore.h>
#include <EngineCore/SpriteRenderer.h>
#include "Enum.h"


SeventhMap::SeventhMap()
{
	{
		USpriteRenderer* SpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		SpriteRenderer->SetOrder(ERenderOrder::MAP);
		SpriteRenderer->SetSprite("7thMap.png");

		FVector2D MapScale = SpriteRenderer->SetSpriteScale(1.0f);
		SpriteRenderer->SetComponentLocation(MapScale.Half());

	}
	
	{
		USpriteRenderer* ColSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
		ColSpriteRenderer->SetOrder(ERenderOrder::COLLISION);
		ColSpriteRenderer->SetSprite("7thColMap.png");

		FVector2D MapScale = ColSpriteRenderer->SetSpriteScale(1.0f);
		ColSpriteRenderer->SetComponentLocation(MapScale.Half());
	}

}


SeventhMap::~SeventhMap()
{
}

