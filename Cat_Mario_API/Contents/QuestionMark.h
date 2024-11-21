#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/2DCollision.h>

// Ό³Έν :
class QuestionMark : public AActor
{
public:
	// constrcuter destructer
	QuestionMark();
	~QuestionMark();

	// delete Function
	QuestionMark(const QuestionMark& _Other) = delete;
	QuestionMark(QuestionMark&& _Other) noexcept = delete;
	QuestionMark& operator=(const QuestionMark& _Other) = delete;
	QuestionMark& operator=(QuestionMark&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
	bool IsQGone = false;

protected:

private:
	class USpriteRenderer* QMarkRenderer;
	U2DCollision* CollisionComponent;
	
};

