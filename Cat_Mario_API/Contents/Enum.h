#pragma once

// Ό³Έν :
enum class ERenderOrder
{
	HIDDEN = -11,
	COLLISION = -10,
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
	BouncyObject,
	SquareBlock,
	CoinBox,
	Prop,

};