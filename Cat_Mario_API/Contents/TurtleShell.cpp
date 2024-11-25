#include "TurtleShell.h"

TurtleShell::TurtleShell()
{
}

TurtleShell::~TurtleShell()
{
}

void TurtleShell::BeginPlay()
{
	Super::BeginPlay();
}

void TurtleShell::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Move(_DeltaTime);
	IsKilled(_DeltaTime);

	GetOutOfBox(_DeltaTime);
	RiseUp(_DeltaTime);
}
