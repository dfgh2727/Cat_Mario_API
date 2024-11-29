#pragma once
#include "CoinBox.h"

// Ό³Έν :
class InfiniteCoinBox : public CoinBox
{
public:
	// constrcuter destructer
	InfiniteCoinBox();
	~InfiniteCoinBox();

	// delete Function
	InfiniteCoinBox(const InfiniteCoinBox& _Other) = delete;
	InfiniteCoinBox(InfiniteCoinBox&& _Other) noexcept = delete;
	InfiniteCoinBox& operator=(const InfiniteCoinBox& _Other) = delete;
	InfiniteCoinBox& operator=(InfiniteCoinBox&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:

};

