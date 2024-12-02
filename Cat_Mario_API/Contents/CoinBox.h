#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>
#include <EnginePlatform/EngineSound.h>

// Ό³Έν :
class CoinBox : public AActor
{
public:
	// constrcuter destructer
	CoinBox();
	~CoinBox();

	// delete Function
	CoinBox(const CoinBox& _Other) = delete;
	CoinBox(CoinBox&& _Other) noexcept = delete;
	CoinBox& operator=(const CoinBox& _Other) = delete;
	CoinBox& operator=(CoinBox&& _Other) noexcept = delete;


	void RenderCollisionComponent();
	virtual void BlockDisappear(float _DeltaTime);
	void CoinShowUP();
	//bool CollideWithCat(float _DeltaTime);

protected:
	U2DCollision* CollisionComponent;

private:
	class USpriteRenderer* QBlockRenderer;
	USoundPlayer BGMPlayer;

	//bool IsHit = false;
};

