#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class BBBRender : public AActor
{
public:
	// constrcuter destructer
	BBBRender();
	~BBBRender();

	// delete Function
	BBBRender(const BBBRender& _Other) = delete;
	BBBRender(BBBRender&& _Other) noexcept = delete;
	BBBRender& operator=(const BBBRender& _Other) = delete;
	BBBRender& operator=(BBBRender&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	U2DCollision* CollisionComponent;
};

