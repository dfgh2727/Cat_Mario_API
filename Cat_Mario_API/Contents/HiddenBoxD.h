#pragma once
#include "CoinBox.h"

// Ό³Έν :
class HiddenBoxD : public CoinBox
{
public:
	// constrcuter destructer
	HiddenBoxD();
	~HiddenBoxD();

	// delete Function
	HiddenBoxD(const HiddenBoxD& _Other) = delete;
	HiddenBoxD(HiddenBoxD&& _Other) noexcept = delete;
	HiddenBoxD& operator=(const HiddenBoxD& _Other) = delete;
	HiddenBoxD& operator=(HiddenBoxD&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void BlockDisappear(float _DeltaTime) override;
	void BlockShowUP();

protected:

private:
	class USpriteRenderer* DarkRenderer;
};

