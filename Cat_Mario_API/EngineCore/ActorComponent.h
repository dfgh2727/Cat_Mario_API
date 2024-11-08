#pragma once
#include <EngineBase/Object.h>
#include <EngineCore/ActorComponent.h>
#include <EngineCore/Actor.h>

// ���� :
class UActorComponent : public UObject
{
public:
	// ���͸��� ParentActor �����Ҽ� �ְ� �����ϱ� ���ؼ� �Ʒ��� ���� §��.
	friend class AActor;

	typedef UActorComponent Super;

	// constrcuter destructer
	UActorComponent();
	// ��üȭ ����Ű�� �ϴ¹��� �ϳ�
	~UActorComponent();

	// delete Function
	UActorComponent(const UActorComponent& _Other) = delete;
	UActorComponent(UActorComponent&& _Other) noexcept = delete;
	UActorComponent& operator=(const UActorComponent& _Other) = delete;
	UActorComponent& operator=(UActorComponent&& _Other) noexcept = delete;

	virtual void BeginPlay() {}
	// ��ŸŸ���̶� �����ΰ�?
	virtual void ComponentTick(float _DeltaTime) {}

	class AActor* GetActor()
	{
		return ParentActor;
	}

	bool IsActive() override
	{
		// �������� �ڽ��� ���� ���Ϳ��� ���ӵȴ�.
		// �θ�        true            true
		return UObject::IsActive() && UActorComponent::GetActor()->IsActive();
	}


	bool IsDestroy() override
	{
		// �θ�        true            true
		return UObject::IsDestroy() || UActorComponent::GetActor()->IsDestroy();
	}


protected:

private:
	class AActor* ParentActor;
};

