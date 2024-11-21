#include "PreCompile.h"
#include "QuestionMark.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

QuestionMark::QuestionMark()
{
    QMarkRenderer = CreateDefaultSubObject<USpriteRenderer>();
	QMarkRenderer->SetSprite("QBlock.png");
	QMarkRenderer->SetOrder(ERenderOrder::BLOCK);
	QMarkRenderer->SetComponentScale({ 60, 60 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	DebugOn();
}

QuestionMark::~QuestionMark()
{
}

void QuestionMark::BeginPlay()
{
	Super::BeginPlay();
}

void QuestionMark::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead);
	if (nullptr != Result)
	{
		this->Destroy();
	}

}
