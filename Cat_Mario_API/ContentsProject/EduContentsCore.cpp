#include "PreCompile.h"
#include "EduContentsCore.h"
#include <EngineCore/EngineAPICore.h>

#include "PlayGameMode.h"
#include "Player.h"


EduContentsCore::EduContentsCore()
{
}

EduContentsCore::~EduContentsCore()
{
}

// ������ ����ǰ� �� 1�� ����ȴ�.
void EduContentsCore::BeginPlay()
{
	// MyWindow.Open();

	// �ƹ� ���� ���� �ڵ�.
	// �ִ� �Ե��� ��������Ѵ�.
	// TitleLevel = new ULevel();
	
	// ��ü�� �����ϴ� �Լ��� �������ִµ� �����ϸ� �ȵȴٴ°�.
	// �̰� ���ؼ� �ȸ��� �ֵ� => �� �ƹ��� ���� ���� ���ɼ��� ����.
	
	//UEngineAPICore::GetCore()->CreateLevel("Title");
	UEngineAPICore::GetCore()->GetMainWindow().SetWindowTitle("EduWindow");

	UEngineAPICore::GetCore()->CreateLevel<APlayGameMode, APlayer>("Play");
	//UEngineAPICore::GetCore()->CreateLevel("End");

	UEngineAPICore::GetCore()->OpenLevel("Play");

}

void EduContentsCore::Tick()
{
	// ���� ���� �뵵�� ã�� ���ؼ� ������� �ʴ� �Լ��Դϴ�.
}