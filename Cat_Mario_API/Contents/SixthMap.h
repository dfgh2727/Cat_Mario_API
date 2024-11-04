#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class SixthMap : public AActor
{
public:
	// constrcuter destructer
	SixthMap();
	~SixthMap();

	// delete Function
	SixthMap(const SixthMap& _Other) = delete;
	SixthMap(SixthMap&& _Other) noexcept = delete;
	SixthMap& operator=(const SixthMap& _Other) = delete;
	SixthMap& operator=(SixthMap&& _Other) noexcept = delete;

protected:

private:

};

