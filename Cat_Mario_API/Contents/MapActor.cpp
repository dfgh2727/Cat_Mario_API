#include "PreCompile.h"
#include "MapActor.h"
#include <EngineCore/ImageManager.h>

AMapActor::AMapActor()
{
}

AMapActor::~AMapActor()
{
}

void AMapActor::SetMapImage(std::string_view _MapImageName)
{
	MapImage = UImageManager::GetInst().FindImage(_MapImageName);
}

void AMapActor::SetColImage(std::string_view _ColImageName)
{
	ColImage = UImageManager::GetInst().FindImage(_ColImageName);
}

