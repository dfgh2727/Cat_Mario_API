#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class DeathCount : public AActor
{
public:
	// constrcuter destructer
	DeathCount();
	~DeathCount();

	// delete Function
	DeathCount(const DeathCount& _Other) = delete;
	DeathCount(DeathCount&& _Other) noexcept = delete;
	DeathCount& operator=(const DeathCount& _Other) = delete;
	DeathCount& operator=(DeathCount&& _Other) noexcept = delete;

protected:

private:

};

