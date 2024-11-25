#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class TurtleShell : public AMapActor
{
public:
	// constrcuter destructer
	TurtleShell();
	~TurtleShell();

	// delete Function
	TurtleShell(const TurtleShell& _Other) = delete;
	TurtleShell(TurtleShell&& _Other) noexcept = delete;
	TurtleShell& operator=(const TurtleShell& _Other) = delete;
	TurtleShell& operator=(TurtleShell&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:

};

