#pragma once
#include "MysteryBox.h"

// Ό³Έν :
class MBwithCoin : public MysteryBox
{
public:
	// constrcuter destructer
	MBwithCoin();
	~MBwithCoin();

	// delete Function
	MBwithCoin(const MBwithCoin& _Other) = delete;
	MBwithCoin(MBwithCoin&& _Other) noexcept = delete;
	MBwithCoin& operator=(const MBwithCoin& _Other) = delete;
	MBwithCoin& operator=(MBwithCoin&& _Other) noexcept = delete;

	void BeginPlay();
	void Tick(float _DeltaTime);

	void Show() override;

protected:

private:

};

