#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class EndImage : public AActor
{
public:
	// constrcuter destructer
	EndImage();
	~EndImage();

	// delete Function
	EndImage(const EndImage& _Other) = delete;
	EndImage(EndImage&& _Other) noexcept = delete;
	EndImage& operator=(const EndImage& _Other) = delete;
	EndImage& operator=(EndImage&& _Other) noexcept = delete;

protected:

private:

};

