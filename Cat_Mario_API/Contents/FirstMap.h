#pragma once
#include <EngineCore/Actor.h>

// ���� :
class FirstMap : public AActor
{
public:
	// constrcuter destructer
	FirstMap();
	~FirstMap();

	// delete Function
	FirstMap(const FirstMap& _Other) = delete;
	FirstMap(FirstMap&& _Other) noexcept = delete;
	FirstMap& operator=(const FirstMap& _Other) = delete;
	FirstMap& operator=(FirstMap&& _Other) noexcept = delete;

protected:

private:

};

