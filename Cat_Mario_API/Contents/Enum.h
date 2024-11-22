#pragma once

// Ό³Έν :
enum class ERenderOrder
{
	COLLISION = -10,
	HIDDEN = -9,
	MAP = -8,
	PROP = -1,
	PLAYER = 0,
	BLOCK = 0,
	PIPE = 9,
	UI = 10
};

enum class ECollisionGroup
{
	PlayerHead,
	PlayerBody,
	PlayerFoot,
	MonsterBody,
	SquareBlock,
	Prop,
};