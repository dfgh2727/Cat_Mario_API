#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// ���� :
class QBlockwithWC : public AActor
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

	/*void BlockDisappear(float _DeltaTime);
	void CoinShowUP();*/

protected:

private:
	class USpriteRenderer* QBlockRenderer;
	U2DCollision* CollisionComponent;
};

