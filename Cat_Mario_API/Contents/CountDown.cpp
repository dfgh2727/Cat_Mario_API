#include "PreCompile.h"

#include "CountDown.h"

CountDown::CountDown()
{
	for (size_t i = 0; i < 10; i++)
	{
		// ī�޶� �������� �̳༮�� �������� �ʴ´�.
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

