#pragma once
#include <EngineBase/EngineResources.h>
#include <map>

#include "ThirdParty/FMOD/inc/fmod.hpp"

// ���� �÷��̾�
// ����ϴ� ���忡 ���� ������ 
class USoundPlayer
{
public:
	friend class UEngineSound;

	void On()
	{
		Control->setPaused(false);
	}

	void Off()
	{
		Control->setPaused(true);
	}

	void OnOffSwtich()
	{
		bool Check = false;
		Control->getPaused(&Check);

		if (true == Check)
		{
			Control->setPaused(false);
		}
		else 
		{
			Control->setPaused(true);
		}
	}


	void Loop(int Count = -1)
	{
		Control->setLoopCount(Count);
	}

private:
	// ä���� �� ���� �����Ŀ� ���� ������ �����ϴ�.
	FMOD::Channel* Control = nullptr;
};

// ���� : ���� �������� ����Ÿ�Ϸ� ¥�ڽ��ϴ�.
class UEngineSound : public UEngineResources
{
public:
	// constrcuter destructer
	UEngineSound();
	~UEngineSound();

	// delete Function
	UEngineSound(const UEngineSound& _Other) = delete;
	UEngineSound(UEngineSound&& _Other) noexcept = delete;
	UEngineSound& operator=(const UEngineSound& _Other) = delete;
	UEngineSound& operator=(UEngineSound&& _Other) noexcept = delete;

	// ������� �������� ����� �̿��Ϸ���
	// FMOD�� system������Ʈ ����� �մϴ�.
	// �츮�� ���� �����ִ°Ͱ� ����.

	static void Load(std::string_view _Path);
	static void Load(std::string_view _Name, std::string_view _Path);
	static USoundPlayer Play(std::string_view _Name);
	static UEngineSound* Find(std::string_view _Name);
	static void Release();

	static void Update();

protected:

private:
	static std::map<std::string, UEngineSound*> Sounds;

	FMOD::Sound* SoundHandle;

	bool ResLoad(std::string_view _Path);
};
