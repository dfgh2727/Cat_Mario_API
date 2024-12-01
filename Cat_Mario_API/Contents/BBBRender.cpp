#include "PreCompile.h"
#include "BBBRender.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "MarioCat.h"

BBBRender::BBBRender()
{
	USpriteRenderer* BBBRenderRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BBBRenderRenderer->SetSprite("BBreakingBlock.png");
	BBBRenderRenderer->SetOrder(ERenderOrder::BLOCK);
	BBBRenderRenderer->SetComponentScale({ 60, 60 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::Prop);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	DebugOn();

}

BBBRender::~BBBRender()
{
}

void BBBRender::BeginPlay()
{
	Super::BeginPlay();
}

void BBBRender::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	MarioCat* MainPlayer = GetWorld()->GetPawn< MarioCat>();
	FVector2D GForce = MainPlayer->GetGravityForce();
	FVector2D CatJumpPower = MainPlayer->GetJumpPower();

	if (CatJumpPower.Y * (-1.0f) >= GForce.Y)
	{
		AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead);
		if (nullptr != Result)
		{
			this->Destroy();
		}
	}
}
