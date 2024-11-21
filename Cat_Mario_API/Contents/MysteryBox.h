#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class MysteryBox : public AActor
{
public:
	// constrcuter destructer
	MysteryBox();
	~MysteryBox();

	// delete Function
	MysteryBox(const MysteryBox& _Other) = delete;
	MysteryBox(MysteryBox&& _Other) noexcept = delete;
	MysteryBox& operator=(const MysteryBox& _Other) = delete;
	MysteryBox& operator=(MysteryBox&& _Other) noexcept = delete;

	void RenderQBlock();
	void Disapper();
	virtual void Show();

protected:

private:
	class USpriteRenderer* QBlockRenderer;
	U2DCollision* CollisionComponent;
};

