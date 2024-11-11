#include "PreCompile.h"
#include "GoingUpBlock.h"

#include <EngineCore/SpriteRenderer.h>

GoingUpBlock::GoingUpBlock()
{
	GoingUpBlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	GoingUpBlockRenderer->SetSprite("QBlock.png");
	GoingUpBlockRenderer->SetComponentScale({ 100, 100 });
}

GoingUpBlock::~GoingUpBlock()
{
}

void GoingUpBlock::BeginPlay()
{

}

void GoingUpBlock::Tick(float _DeltaTime)
{

}
