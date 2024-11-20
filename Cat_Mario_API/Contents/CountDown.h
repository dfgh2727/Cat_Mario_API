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

	void SetTextSpriteName(const std::string _Text);

	void SetTextScale(FVector2D _TextScale)
	{
		TextScale = _TextScale;
	}

	template<typename EnumType>
	void SetOrder(EnumType _Order)
	{
		SetOrder(static_cast<int>(_Order));
	}

	void SetOrder(int _Order);

	void SetValue(int _Score);

	void ShowMinus();


protected:

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

	std::string TextSpriteName;
	FVector2D TextScale;
	class USpriteRenderer* MinusRenderer;
	std::vector<class USpriteRenderer*> NumRenderer;

};

