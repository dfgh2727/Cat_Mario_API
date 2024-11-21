#pragma once
#include "MysteryBox.h"

// Ό³Έν :
class MBwithWhiteCircle : public MysteryBox
{
public:
	// constrcuter destructer
	MBwithWhiteCircle();
	~MBwithWhiteCircle();

	// delete Function
	MBwithWhiteCircle(const MBwithWhiteCircle& _Other) = delete;
	MBwithWhiteCircle(MBwithWhiteCircle&& _Other) noexcept = delete;
	MBwithWhiteCircle& operator=(const MBwithWhiteCircle& _Other) = delete;
	MBwithWhiteCircle& operator=(MBwithWhiteCircle&& _Other) noexcept = delete;

	void BeginPlay();
	void Tick(float _DeltaTime);

	void Show() override;

protected:

private:

};

