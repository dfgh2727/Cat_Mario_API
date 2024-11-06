#pragma once
#include <vector>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/ImageManager.h>

#include <EngineCore/Actor.h>


// Ό³Έν :
class CountDown : public AActor
{
public:
	// constrcuter destructer
	CountDown();
	~CountDown();

	// delete Function
	CountDown(const CountDown& _Other) = delete;
	CountDown(CountDown&& _Other) noexcept = delete;
	CountDown& operator=(const CountDown& _Other) = delete;
	CountDown& operator=(CountDown&& _Other) noexcept = delete;

protected:

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

	std::string TextSpriteName;
	FVector2D TextScale;
	std::vector<class USpriteRenderer*> NumRenderer;

};

