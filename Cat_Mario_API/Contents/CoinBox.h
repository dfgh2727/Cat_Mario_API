#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

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
	void BlockDisappear();
	void CoinShowUP();


protected:

private:
	class USpriteRenderer* QBlockRenderer;
	U2DCollision* CollisionComponent;
};

