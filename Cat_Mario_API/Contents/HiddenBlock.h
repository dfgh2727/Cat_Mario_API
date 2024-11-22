#pragma once

// Ό³Έν :
class HiddenBlock
{
public:
	// constrcuter destructer
	HiddenBlock();
	~HiddenBlock();

	// delete Function
	HiddenBlock(const HiddenBlock& _Other) = delete;
	HiddenBlock(HiddenBlock&& _Other) noexcept = delete;
	HiddenBlock& operator=(const HiddenBlock& _Other) = delete;
	HiddenBlock& operator=(HiddenBlock&& _Other) noexcept = delete;

protected:

private:

};

