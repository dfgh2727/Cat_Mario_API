#pragma once

// ���� :
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
	MonsterBody,
	BouncyObject,
	SuperBouncyObject,
	SquareBlock,
	CoinBox,
	Prop,
	MysteryBox,
	TurtleShell,
	Dozer,
	BreakingBlock,

};