#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/EngineAPICore.h>

APlayer::APlayer()
{
	// UEngineAPICore::GetCore()->CreateLevel("Title");
	SetActorLoaction({100, 100});
	SetActorScale({ 100, 100 });
}

APlayer::~APlayer()
{
}


void APlayer::BeginPlay()
{
	// �⺻ũ�Ⱑ �������� �����Ƿ� 
	// �⺻ ũ�� �� �⺻ �������� ��������� �մϴ�.


}

void APlayer::Tick(float _DeltaTime)
{
	// Time::DeltaTime;

	// �����е��� ��ǻ�Ͱ� 1�������̰�
	// �������� ��ǻ�Ͱ� 2��������

	// ���ӽ����ϰ� ��������?

	//         ������  ����ǻ�ʹ�
	// 0.5��             0.5        =+> 0.5         // 0.0, 0.0, => 0.5, 0.0
	// 1.0��    1.0f     0.5        =+> 1.0         // 0.5, 0.0, => 1.0, 0.0
	// 1.5��             0.5        =+> 1.5 - 1.0
	// 2.0��    1.0f     0.5        =+> 1.0         // 1.0, 0.0, => 2.0, 0.0

	// ��Ÿ��


	// �������� 
	// 0.0, 0.0, => 1.0, 0.0

	// ���� ������� �Ѵ�.
	// ���ɷȾ�
	// ��ǻ���� ���ɰ� ������� => ���� ���� ������ �����ֱ� ���ؼ� �Դϴ�. 
	AddActorLoaction(FVector2D::RIGHT * _DeltaTime * Speed);
}