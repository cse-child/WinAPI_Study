#include "Framework.h"

BlockManager::BlockManager()
{
	for (UINT i = 0; i < FLOOR_COUNT; i++)
	{
		Block* block = new Block();
		block->Pos().x = block->Size().x * i + block->Half().x;
		block->Pos().y = WIN_HEIGHT - block->Half().y;

		blocks.push_back(block);
	}

	for (UINT i = 0; i < 5; i++)
	{
		Block* block = new Block();
		block->Pos().x = CENTER_X + block->Size().x * i + block->Half().x;
		block->Pos().y = CENTER_Y + 100.0f;

		blocks.push_back(block);
	}

	for (UINT i = 0; i < 5; i++)
	{
		Block* block = new Block();
		block->Pos().x = 100.0f + block->Size().x * i + block->Half().x;
		block->Pos().y = CENTER_Y + 100.0f;

		blocks.push_back(block);
	}
}

BlockManager::~BlockManager()
{
	for (Block* block : blocks)
		delete block;

	blocks.clear();
}

void BlockManager::Update()
{
	for (Block* block : blocks)
		block->Update();
}

void BlockManager::Render(HDC hdc)
{
	for (Block* block : blocks)
		block->Render(hdc);
}

Vector2 BlockManager::GetBlockSize()
{
	return blocks[0]->Size();
}

Rect* BlockManager::IsCollision(Rect* rect)
{
	for (Block* block : blocks)
	{
		if (block->IsCollision(rect))
			return block;
	}
    return nullptr;
}
