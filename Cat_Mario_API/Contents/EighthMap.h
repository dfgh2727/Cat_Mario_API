#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class EighthMap : public AActor
{
public:
	// constrcuter destructer
	EighthMap();
	~EighthMap();

	// delete Function
	EighthMap(const EighthMap& _Other) = delete;
	EighthMap(EighthMap&& _Other) noexcept = delete;
	EighthMap& operator=(const EighthMap& _Other) = delete;
	EighthMap& operator=(EighthMap&& _Other) noexcept = delete;

protected:

private:

};

