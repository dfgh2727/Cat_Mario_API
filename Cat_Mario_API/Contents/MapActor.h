#pragma once

#include <EngineCore/Actor.h>

// Ό³Έν :
class AMapActor : public AActor
{
public:
	// constrcuter destructer
	AMapActor();
	~AMapActor();

	// delete Function
	AMapActor(const AMapActor& _Other) = delete;
	AMapActor(AMapActor&& _Other) noexcept = delete;
	AMapActor& operator=(const AMapActor& _Other) = delete;
	AMapActor& operator=(AMapActor&& _Other) noexcept = delete;

	UEngineWinImage* SetColImage(std::string_view _ColImageName);
	UEngineWinImage* SetMapImage(std::string_view _MapImageName);

protected:
	class UEngineWinImage* ColImage = nullptr;
	UEngineWinImage* MapImage = nullptr;

private:
};

