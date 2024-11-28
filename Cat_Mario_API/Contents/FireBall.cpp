#include "PreCompile.h"
#include "FireBall.h"

#include <EngineCore/SpriteRenderer.h>


#include "Enum.h"

UEngineRandom FireBall::Random;

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

void FireBall::BeginPlay()
{
	Super::BeginPlay();

	FBVelocity = FVector2D::ZERO;
	float XValue = Random.Randomfloat(-170.0f, 170.0f);
	float YValue = Random.Randomfloat(-900.0f, -700.0f);

	FBVelocity.X = XValue;
	FBVelocity.Y = YValue;

}

void FireBall::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);



	AddActorLocation(FBVelocity * _DeltaTime);


	Gravity(_DeltaTime);
}

void FireBall::Gravity(float _DeltaTime)
{
	AddActorLocation(GravityForce * _DeltaTime);
	GravityForce += FVector2D::DOWN * _DeltaTime * 1200.0f;
}

