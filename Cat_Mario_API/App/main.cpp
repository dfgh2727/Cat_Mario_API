#include "PreCompile.h"
#include <Contents/CatMarioGame.h>


#include <EngineCore/EngineAPICore.h>

#pragma comment (lib, "EngineCore.lib")
#pragma comment (lib, "Contents.lib")


#include <EngineBase/EngineTimer.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	CatMarioGame GameStart;
	return UEngineAPICore::EngineStart(hInstance, &GameStart);
}