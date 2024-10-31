
#pragma once

// Ό³Έν :
class CatMarioGame
{
public:
	// constrcuter destructer
	CatMarioGame();
	~CatMarioGame();

	// delete Function
	CatMarioGame(const CatMarioGame& _Other) = delete;
	CatMarioGame(CatMarioGame&& _Other) noexcept = delete;
	CatMarioGame& operator=(const CatMarioGame& _Other) = delete;
	CatMarioGame& operator=(CatMarioGame&& _Other) noexcept = delete;

protected:

private:

};

