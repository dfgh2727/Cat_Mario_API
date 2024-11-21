#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class PipeHead : public AActor
{
public:
	// constrcuter destructer
	PipeHead();
	~PipeHead();

	// delete Function
	PipeHead(const PipeHead& _Other) = delete;
	PipeHead(PipeHead&& _Other) noexcept = delete;
	PipeHead& operator=(const PipeHead& _Other) = delete;
	PipeHead& operator=(PipeHead&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	U2DCollision* CollisionComponent;
};

