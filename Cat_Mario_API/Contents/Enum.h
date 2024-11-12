#pragma once

// Ό³Έν :
enum class ERenderOrder
{
	COLLISION = -10,
	HIDDEN = -9,
	MAP = -8,
	PLAYER = 0,
	OBJECT = 0,
	UI = 10
};

enum class ECollisionGroup
{
	PlayerHead,
	PlayerBody,
	PlayerFoot,
	MonsterBody,
	SquareBlock,
};