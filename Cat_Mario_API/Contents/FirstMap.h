#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class FirstMap : public AActor
{
public:
	// constrcuter destructer
	FirstMap();
	~FirstMap();

	// delete Function
	FirstMap(const FirstMap& _Other) = delete;
	FirstMap(FirstMap&& _Other) noexcept = delete;
	FirstMap& operator=(const FirstMap& _Other) = delete;
	FirstMap& operator=(FirstMap&& _Other) noexcept = delete;

	void Tick(float _DeltaTime) override;

protected:

private:

	class USpriteRenderer* BackSpriteRenderer;
	class USpriteRenderer* ColSpriteRenderer;
};

