#pragma once

// Ό³Έν :
enum class ERenderOrder
{
	HIDDEN = -11,
	COLLISION = -10,
	MAP = -8,
	PROP = -1,
	PLAYER = 0,
	BLOCK = 1,
	PIPE = 9,
	UI = 10
};

enum class ECollisionGroup
{
	PlayerHead,
	PlayerBody,
	PlayerFoot,
	ColPlayer,
	MonsterBody,
	BouncyObject,
	SuperBouncyObject,
	SquareBlock,
	FDBlock,
	CoinBox,
	Prop,
	MysteryBox,
	TurtleShell,
	Dozer,
	BreakingBlock,
	None,
	BigBody,
	GettingBig,

};