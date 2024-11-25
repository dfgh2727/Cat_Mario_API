#include "PreCompile.h"
#include "Staff.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineCoreDebug.h>
#include <EngineCore/Level.h>

#include "Enum.h"
#include "MarioCat.h"

Staff::Staff()
{
}

Staff::~Staff()
{
}

void Staff::BeginPlay()
{
	Super::BeginPlay();
}

void Staff::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	AActor* Result = CollisionComponent->CollisionOnce(ECollisionGroup::PlayerBody);
	if (nullptr != Result)
	{
		MarioCat* MainPlayer = GetWorld()->GetPawn<MarioCat>();
		this->Destroy();
	}

}

