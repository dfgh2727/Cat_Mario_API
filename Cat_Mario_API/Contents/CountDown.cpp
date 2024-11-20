#include "PreCompile.h"

#include "CountDown.h"
#include "Enum.h"

CountDown::CountDown()
{
	MinusRenderer = CreateDefaultSubObject<USpriteRenderer>();
	MinusRenderer->SetSprite("CMnumMinus.png");

	for (size_t i = 0; i < 12; i++)
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

void CountDown::BeginPlay()
{
}

void CountDown::Tick(float _DeltaTime)
{

}

void CountDown::SetTextSpriteName(const std::string _Text)
{
	TextSpriteName = _Text;

	for (size_t i = 0; i < NumRenderer.size(); i++)
	{
		NumRenderer[i]->SetSprite(TextSpriteName);
	}
}

void CountDown::SetOrder(int _Order)
{
	for (size_t i = 0; i < NumRenderer.size(); i++)
	{
		NumRenderer[i]->SetOrder(_Order);
	}

}

void CountDown::SetValue(int _Score)
{
	std::string Number = std::to_string(_Score);

	if (NumRenderer.size() <= Number.size())
	{
		MSGASSERT("자리수를 넘겼습니다.");
		return;
	}


	FVector2D Pos = FVector2D::ZERO;

	for (size_t i = 0; i < Number.size(); i++)
	{
		char Value = Number[i] - '0';
		NumRenderer[i]->SetSprite(TextSpriteName, Value);
		NumRenderer[i]->SetComponentScale(TextScale);
		NumRenderer[i]->SetComponentLocation(Pos);
		Pos.X += TextScale.X;
		NumRenderer[i]->SetActive(true);
	}

	MinusRenderer->SetComponentLocation({ -TextScale.X, 0.0f});

	for (size_t i = Number.size(); i < NumRenderer.size(); i++)
	{
		NumRenderer[i]->SetActive(false);
	}

}

void CountDown::ShowMinus()
{
	MinusRenderer->SetOrder(ERenderOrder::UI);
	MinusRenderer->SetComponentScale({ 25, 50 });
}

