#pragma once

// Ό³Έν :
class FireBall
{
public:
	// constrcuter destructer
	FireBall();
	~FireBall();

	// delete Function
	FireBall(const FireBall& _Other) = delete;
	FireBall(FireBall&& _Other) noexcept = delete;
	FireBall& operator=(const FireBall& _Other) = delete;
	FireBall& operator=(FireBall&& _Other) noexcept = delete;

protected:

private:

};

