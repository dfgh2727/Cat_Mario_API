#include "PreCompile.h"
#include "HiddenBoxS.h"
#include "Enum.h"
#include "BNormalBlock.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

HiddenBoxS::HiddenBoxS()
{
	SkyRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SkyRenderer->SetSprite("SkyBlock.png");
	SkyRenderer->SetOrder(ERenderOrder::HIDDEN);
	SkyRenderer->SetComponentScale({ 60, 60 });

	RenderCollisionComponent();
}

HiddenBoxS::~HiddenBoxS()
{
}

void HiddenBoxS::BeginPlay()
{
	Super::BeginPlay();
}

void HiddenBoxS::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	BlockDisappear(_DeltaTime);
}

void HiddenBoxS::BlockDisappear(float _DeltaTime)
{
	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerHead);
	if (nullptr != Result)
	{
		CoinShowUP();
		BlockShowUP();
		this->Destroy();
	}
}

void HiddenBoxS::BlockShowUP()
{
	FVector2D PresentPos = this->GetActorLocation();
	BNormalBlock* TheBlock = GetWorld()->SpawnActor<BNormalBlock>();
	TheBlock->SetActorLocation(PresentPos);
}
