#pragma once
#include "MapActor.h"
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class QBlockwithMushroomN : public AMapActor
{
public:
	// constrcuter destructer
	QBlockwithMushroomN();
	~QBlockwithMushroomN();

	// delete Function
	QBlockwithMushroomN(const QBlockwithMushroomN& _Other) = delete;
	QBlockwithMushroomN(QBlockwithMushroomN&& _Other) noexcept = delete;
	QBlockwithMushroomN& operator=(const QBlockwithMushroomN& _Other) = delete;
	QBlockwithMushroomN& operator=(QBlockwithMushroomN&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void BlockDisappear(float _DeltaTime);
	void MushroomShowUP();

protected:

private:
	class USpriteRenderer* QBlockRenderer;
	U2DCollision* CollisionComponent;
};

