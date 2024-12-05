#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class GBTileBlock : public AActor
{
public:
	// constrcuter destructer
	GBTileBlock();
	~GBTileBlock();

	// delete Function
	GBTileBlock(const GBTileBlock& _Other) = delete;
	GBTileBlock(GBTileBlock&& _Other) noexcept = delete;
	GBTileBlock& operator=(const GBTileBlock& _Other) = delete;
	GBTileBlock& operator=(GBTileBlock&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ItsBroken();

protected:

private:

	class USpriteRenderer* GBTileBlockRenderer;
	U2DCollision* CollisionComponent;

	bool Broken = false;
};

