#pragma once
#include <EngineCore/Actor.h>

// ���� :
class FifthMap : public AActor
{
public:
	// constrcuter destructer
	FifthMap();
	~FifthMap();

	// delete Function
	FifthMap(const FifthMap& _Other) = delete;
	FifthMap(FifthMap&& _Other) noexcept = delete;
	FifthMap& operator=(const FifthMap& _Other) = delete;
	FifthMap& operator=(FifthMap&& _Other) noexcept = delete;

protected:

private:

};

