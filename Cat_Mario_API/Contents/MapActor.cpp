#include "PreCompile.h"
#include "MapActor.h"
#include <EngineCore/ImageManager.h>

AMapActor::AMapActor()
{
}

AMapActor::~AMapActor()
{
}

UEngineWinImage* AMapActor::SetMapImage(std::string_view _MapImageName)
{
	UEngineWinImage* MapImage = UImageManager::GetInst().FindImage(_MapImageName);
	return MapImage;
}

UEngineWinImage* AMapActor::SetColImage(std::string_view _ColImageName)
{
	UEngineWinImage* ColImage = UImageManager::GetInst().FindImage(_ColImageName);
	return ColImage;
}

