#pragma once
#include <EngineCore/EngineAPICore.h>

// ���� :
class ContentsBox : public UContentsCore
{
public:
	
	ContentsBox(); // ������
	~ContentsBox(); //�Ҹ���

	// delete(�ӽ�)
	ContentsBox(const ContentsBox& _Other) = delete;
	ContentsBox(ContentsBox&& _Other) noexcept = delete;
	ContentsBox& operator=(const ContentsBox& _Other) = delete;
	ContentsBox& operator=(ContentsBox&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick() override;

private:
	ULevel* TitleLevel;
};

