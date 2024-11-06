#include "PreCompile.h"

#include "CountDown.h"

CountDown::CountDown()
{
	for (size_t i = 0; i < 10; i++)
	{
		// 카메라가 움직여도 이녀석은 움직이지 않는다.
		USpriteRenderer* Sprite = CreateDefaultSubObject<USpriteRenderer>();
		Sprite->SetCameraEffect(false);
		NumRenderer.push_back(Sprite);
	}
}

CountDown::~CountDown()
{
}

void CountDown::SetTextSpriteName(const std::string _Text)
{
	TextSpriteName = _Text;

	for (size_t i = 0; i < NumRenderer.size(); i++)
	{
		Renders[i]->SetSprite(TextSpriteName);
	}
}

