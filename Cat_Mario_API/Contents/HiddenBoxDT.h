#pragma once
#include "CoinBox.h"

// Ό³Έν :
class HiddenBoxDT : public CoinBox
{
public:
	// constrcuter destructer
	HiddenBoxDT();
	~HiddenBoxDT();

	// delete Function
	HiddenBoxDT(const HiddenBoxDT& _Other) = delete;
	HiddenBoxDT(HiddenBoxDT&& _Other) noexcept = delete;
	HiddenBoxDT& operator=(const HiddenBoxDT& _Other) = delete;
	HiddenBoxDT& operator=(HiddenBoxDT&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void BlockDisappear(float _DeltaTime) override;
	void BlockShowUP();

protected:

private:
	class USpriteRenderer* SkyRenderer;
};

