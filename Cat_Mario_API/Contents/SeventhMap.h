#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class SeventhMap : public AActor
{
public:
	// constrcuter destructer
	SeventhMap();
	~SeventhMap();

	// delete Function
	SeventhMap(const SeventhMap& _Other) = delete;
	SeventhMap(SeventhMap&& _Other) noexcept = delete;
	SeventhMap& operator=(const SeventhMap& _Other) = delete;
	SeventhMap& operator=(SeventhMap&& _Other) noexcept = delete;

protected:

private:

};

