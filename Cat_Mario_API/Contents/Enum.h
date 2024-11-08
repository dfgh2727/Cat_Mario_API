#pragma once

// Ό³Έν :
enum class ERenderOrder
{
	COLLISION = -10,
	MAP = -9,
	PLAYER = 0,
	UI = 10
};

enum class ECollisionGroup
{
	PlayerBody,
	MonsterBody,
};