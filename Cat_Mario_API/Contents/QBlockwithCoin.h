#pragma once
#include "CoinBox.h"

// Ό³Έν :
class QBlockwithCoin : public CoinBox
{
public:
	// constrcuter destructer
	QBlockwithCoin();
	~QBlockwithCoin();

	// delete Function
	QBlockwithCoin(const QBlockwithCoin& _Other) = delete;
	QBlockwithCoin(QBlockwithCoin&& _Other) noexcept = delete;
	QBlockwithCoin& operator=(const QBlockwithCoin& _Other) = delete;
	QBlockwithCoin& operator=(QBlockwithCoin&& _Other) noexcept = delete;

	void BeginPlay();
	void Tick(float _DeltaTime);

protected:

private:
	class USpriteRenderer* QBlockRenderer;
};

