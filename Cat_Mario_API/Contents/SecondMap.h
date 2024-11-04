#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class SecondMap : public AActor
{
public:
	// constrcuter destructer
	SecondMap();
	~SecondMap();

	// delete Function
	SecondMap(const SecondMap& _Other) = delete;
	SecondMap(SecondMap&& _Other) noexcept = delete;
	SecondMap& operator=(const SecondMap& _Other) = delete;
	SecondMap& operator=(SecondMap&& _Other) noexcept = delete;

protected:

private:

};

