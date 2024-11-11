#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class GoingUpBlock : public AActor
{
public:
	// constrcuter destructer
	GoingUpBlock();
	~GoingUpBlock();

	// delete Function
	GoingUpBlock(const GoingUpBlock& _Other) = delete;
	GoingUpBlock(GoingUpBlock&& _Other) noexcept = delete;
	GoingUpBlock& operator=(const GoingUpBlock& _Other) = delete;
	GoingUpBlock& operator=(GoingUpBlock&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void KeepDistance();


protected:

private:

	class USpriteRenderer* GoingUpBlockRenderer;

};

