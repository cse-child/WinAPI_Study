#pragma once

class BlockManager : public Singleton<BlockManager>
{
private:
	const UINT FLOOR_COUNT = 30;

public:
	BlockManager();
	~BlockManager();

	void Update();
	void Render(HDC hdc);

	Vector2 GetBlockSize();

	Rect* IsCollision(Rect* rect);

private:
	vector<Block*> blocks;
};