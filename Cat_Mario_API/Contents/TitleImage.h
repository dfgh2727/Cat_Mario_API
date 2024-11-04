#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class TitleImage : public AActor
{
public:
	// constrcuter destructer
	TitleImage();
	~TitleImage();

	// delete Function
	TitleImage(const TitleImage& _Other) = delete;
	TitleImage(TitleImage&& _Other) noexcept = delete;
	TitleImage& operator=(const TitleImage& _Other) = delete;
	TitleImage& operator=(TitleImage&& _Other) noexcept = delete;

protected:

private:

};

