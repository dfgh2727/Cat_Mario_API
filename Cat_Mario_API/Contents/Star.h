#pragma once

// Ό³Έν :
class Star
{
public:
	// constrcuter destructer
	Star();
	~Star();

	// delete Function
	Star(const Star& _Other) = delete;
	Star(Star&& _Other) noexcept = delete;
	Star& operator=(const Star& _Other) = delete;
	Star& operator=(Star&& _Other) noexcept = delete;

protected:

private:

};

