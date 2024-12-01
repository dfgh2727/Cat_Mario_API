#include "PreCompile.h"
#include "HiddenBoxDT.h"
#include "Enum.h"
#include "GNormalBlock.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>
#include"MarioCat.h"

HiddenBoxDT::HiddenBoxDT()
{
	SkyRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SkyRenderer->SetSprite("DarkBlock.png");
	SkyRenderer->SetOrder(ERenderOrder::HIDDEN);
	SkyRenderer->SetComponentScale({ 60, 60 });

	CollisionComponent = CreateDefaultSubObject<U2DCollision>();
	CollisionComponent->SetComponentScale({ 60, 60 });
	CollisionComponent->SetCollisionGroup(ECollisionGroup::CoinBox);
	CollisionComponent->SetCollisionType(ECollisionType::Rect);

	DebugOn();
}

HiddenBoxDT::~HiddenBoxDT()
{
}

void HiddenBoxDT::BeginPlay()
{
	Super::BeginPlay();
}

void HiddenBoxDT::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	BlockDisappear(_DeltaTime);
}

void HiddenBoxDT::BlockDisappear(float _DeltaTime)
{
	/*MarioCat* MainActor = GetWorld()->GetPawn<MarioCat>();
	FVector2D GForce = MainActor->GetGravityForce();
	FVector2D CatJumpPower = MainActor->GetJumpPower();*/

	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::TurtleShell);
	if (nullptr != Result)
	{
		CoinShowUP();
		BlockShowUP();
		this->Destroy();
	}
}

void HiddenBoxDT::BlockShowUP()
{
	FVector2D PresentPos = this->GetActorLocation();
	GNormalBlock* TheBlock = GetWorld()->SpawnActor<GNormalBlock>();
	TheBlock->SetActorLocation(PresentPos);
}
