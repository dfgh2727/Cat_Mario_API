#include "PreCompile.h"
#include "GoingUpBlock.h"
#include "Enum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Level.h>
#include "MarioCat.h"


GoingUpBlock::GoingUpBlock()
{
	GoingUpBlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	GoingUpBlockRenderer->SetSprite("QBlock.png");
	GoingUpBlockRenderer->SetComponentScale({ 60, 60 });

	{
		U2DCollision* CollisionComponent = CreateDefaultSubObject<U2DCollision>();
		CollisionComponent->SetComponentScale({ 60, 60 });
		CollisionComponent->SetCollisionGroup(ECollisionGroup::SquareBlock);
		CollisionComponent->SetCollisionType(ECollisionType::Rect);
		DebugOn();
	}
}

GoingUpBlock::~GoingUpBlock()
{
}

void GoingUpBlock::BeginPlay()
{
	Super::BeginPlay();
}

void GoingUpBlock::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	KeepDistance();	
}

void GoingUpBlock::KeepDistance()
{

	// 절대 안됨 새로운 마리오를 만드는 코드
	// MarioCat MainPlayer = MarioCat;
	// MarioCat* MainPlayer = new MarioCat();
	
	// 마리오를 쓰고 싶어  마리오를 찾아왔다
	MarioCat* MainPlayer = GetWorld()->GetPawn<MarioCat>();

	FVector2D BlockPos = this->GetActorLocation();
	FVector2D CatPos = (MainPlayer->GetActorLocation()) + FVector2D{ 0, -30 };
	FVector2D Distance = CatPos - BlockPos;

	if (-50.0 <= Distance.X && Distance.X <= 50.0)
	{
		if (Distance.Y <= 80.0 && BlockPos.Y < CatPos.Y)
		{
			AddActorLocation(FVector2D::UP);
		}
		return;
	}
}
