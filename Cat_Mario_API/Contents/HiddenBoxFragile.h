#pragma once
#include "CoinBox.h"

// Ό³Έν :
class HiddenBoxFragile : public CoinBox
{
public:
	// constrcuter destructer
	HiddenBoxFragile();
	~HiddenBoxFragile();

	// delete Function
	HiddenBoxFragile(const HiddenBoxFragile& _Other) = delete;
	HiddenBoxFragile(HiddenBoxFragile&& _Other) noexcept = delete;
	HiddenBoxFragile& operator=(const HiddenBoxFragile& _Other) = delete;
	HiddenBoxFragile& operator=(HiddenBoxFragile&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void BlockDisappear(float _DeltaTime) override;
	void BlockShowUP();

protected:

private:
	class USpriteRenderer* DarkRenderer;
};

