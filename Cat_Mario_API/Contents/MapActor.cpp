#include "PreCompile.h"
#include "MapActor.h"
#include <EngineCore/ImageManager.h>
#include <EnginePlatform/EngineInput.h>

AMapActor::AMapActor()
{
}

AMapActor::~AMapActor()
{
}

void AMapActor::SetMapImage(std::string_view _MapImageName)
{
	this->MapImage = UImageManager::GetInst().FindImage(_MapImageName);
	return ;
}

void AMapActor::SetColImage(std::string_view _ColImageName)
{
	this->ColImage = UImageManager::GetInst().FindImage(_ColImageName);
	return;
}

void AMapActor::DirCheck()
{

	if (true == UEngineInput::GetInst().IsPress(VK_RIGHT))
	{
		DirString = "Right";
	}

	if (true == UEngineInput::GetInst().IsPress(VK_LEFT))
	{
		DirString = "Left";
	}

}

