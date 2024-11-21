#include "PreCompile.h"
#include "MysteryBox.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

MysteryBox::MysteryBox()
{
}

MysteryBox::~MysteryBox()
{
}

void MysteryBox::RenderQBlock()
{
	QBlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	QBlockRenderer->SetSprite("QBlock.png");
	QBlockRenderer->SetOrder(ERenderOrder::BLOCK);
	QBlockRenderer->SetComponentScale({ 60, 60 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
		DebugOn();
	}
}

void MysteryBox::BlockDisappear()
{
	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead);
	if (nullptr != Result)
	{
		Show();
		this->Destroy();
	}
}

void MysteryBox::Show()
{

}


void MysteryBox::RiseUp()
{
	AddActorLocation(FVector2D::UP * 0.25f);
}