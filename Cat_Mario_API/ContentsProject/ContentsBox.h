#pragma once
#include <EngineCore/EngineAPICore.h>

// 설명 :
class ContentsBox : public UContentsCore
{
public:
	
	ContentsBox(); // 생성자
	~ContentsBox(); //소멸자

	// delete(임시)
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

