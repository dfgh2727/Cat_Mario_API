#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class MakeMap : public AActor
{
public:
	// constrcuter destructer
	MakeMap();
	~MakeMap();

	// delete Function
	MakeMap(const MakeMap& _Other) = delete;
	MakeMap(MakeMap&& _Other) noexcept = delete;
	MakeMap& operator=(const MakeMap& _Other) = delete;
	MakeMap& operator=(MakeMap&& _Other) noexcept = delete;

protected:

private:

};

