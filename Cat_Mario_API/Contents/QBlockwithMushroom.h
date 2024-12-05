#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class QBlockwithMushroom : public AMapActor
{
public:
	// constrcuter destructer
	QBlockwithMushroom();
	~QBlockwithMushroom();

	// delete Function
	QBlockwithMushroom(const QBlockwithMushroom& _Other) = delete;
	QBlockwithMushroom(QBlockwithMushroom&& _Other) noexcept = delete;
	QBlockwithMushroom& operator=(const QBlockwithMushroom& _Other) = delete;
	QBlockwithMushroom& operator=(QBlockwithMushroom&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void BlockDisappear(float _DeltaTime);
	void MushroomShowUP();

	bool ItsB = false;

protected:

private:
	class USpriteRenderer* QBlockRenderer;
	U2DCollision* CollisionComponent;
};

