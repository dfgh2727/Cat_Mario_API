#pragma once
#include <EngineCore/Actor.h>


// ���� :
class FourthMap : public AActor
{
public:
	// constrcuter destructer
	FourthMap();
	~FourthMap();

	// delete Function
	FourthMap(const FourthMap& _Other) = delete;
	FourthMap(FourthMap&& _Other) noexcept = delete;
	FourthMap& operator=(const FourthMap& _Other) = delete;
	FourthMap& operator=(FourthMap&& _Other) noexcept = delete;

protected:

private:

};

