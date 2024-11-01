#pragma once

// Ό³Έν :
class KeysForMap
{
public:
	// constrcuter destructer
	KeysForMap();
	~KeysForMap();

	// delete Function
	KeysForMap(const KeysForMap& _Other) = delete;
	KeysForMap(KeysForMap&& _Other) noexcept = delete;
	KeysForMap& operator=(const KeysForMap& _Other) = delete;
	KeysForMap& operator=(KeysForMap&& _Other) noexcept = delete;

protected:

private:

};

