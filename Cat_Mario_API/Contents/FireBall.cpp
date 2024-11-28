#include "PreCompile.h"
#include "FireBall.h"

#include <EngineCore/SpriteRenderer.h>

#include "Enum.h"

FireBall::FireBall()
{
	FBRenderer = CreateDefaultSubObject<USpriteRenderer>();
	FBRenderer->SetSprite("FireBall.png");
	FBRenderer->SetOrder(ERenderOrder::PLAYER);
	FBRenderer->SetComponentScale({ 58, 58 });

	{
		CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 58, 58 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::None);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
	}
	DebugOn();
}

FireBall::~FireBall()
{
}

void FireBall::Gravity(float _DeltaTime)
{
	AddActorLocation(GravityForce * _DeltaTime);
	GravityForce += FVector2D::DOWN * _DeltaTime * 1200.0f;
}

