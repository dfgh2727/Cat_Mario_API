#pragma once
#include "CoinBox.h"

// Ό³Έν :
class HiddenBoxS : public CoinBox
{
public:
	// constrcuter destructer
	HiddenBoxS();
	~HiddenBoxS();

	// delete Function
	HiddenBoxS(const HiddenBoxS& _Other) = delete;
	HiddenBoxS(HiddenBoxS&& _Other) noexcept = delete;
	HiddenBoxS& operator=(const HiddenBoxS& _Other) = delete;
	HiddenBoxS& operator=(HiddenBoxS&& _Other) noexcept = delete;

	void BeginPlay();
	void Tick(float _DeltaTime);

protected:

private:
	class USpriteRenderer* SkyRenderer;
};

