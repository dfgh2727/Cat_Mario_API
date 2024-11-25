#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class QBlockwithWC : public AMapActor
{
public:
	// constrcuter destructer
	QBlockwithWC();
	~QBlockwithWC();

	// delete Function
	QBlockwithWC(const QBlockwithWC& _Other) = delete;
	QBlockwithWC(QBlockwithWC&& _Other) noexcept = delete;
	QBlockwithWC& operator=(const QBlockwithWC& _Other) = delete;
	QBlockwithWC& operator=(QBlockwithWC&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void BlockDisappear(float _DeltaTime);
	void MonsterShowUP();

protected:

private:
	class USpriteRenderer* QBlockRenderer;
	U2DCollision* CollisionComponent;
};

