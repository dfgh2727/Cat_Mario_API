#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class ThirdMap : public AActor
{
public:
	// constrcuter destructer
	ThirdMap();
	~ThirdMap();

	// delete Function
	ThirdMap(const ThirdMap& _Other) = delete;
	ThirdMap(ThirdMap&& _Other) noexcept = delete;
	ThirdMap& operator=(const ThirdMap& _Other) = delete;
	ThirdMap& operator=(ThirdMap&& _Other) noexcept = delete;

protected:

private:

};

