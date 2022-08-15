#include "Framework.h"

BrickManager::BrickManager()
{
    CreateStage();
}

BrickManager::~BrickManager()
{
    ClearStage();
}

void BrickManager::Render(HDC hdc)
{
    for (Brick* brick : bricks)
        brick->Render(hdc);
}

Direction BrickManager::Collision(Circle* circle)
{
    for (Brick* brick : bricks)
    {
        Direction result = brick->Collision(circle);
        if (result != Direction::NONE)
            return result;
    }

    return Direction::NONE;
}

void BrickManager::CreateStage()
{
    int width = 10;
    int height = 4;

    Vector2 size;
    size.x = WIN_WIDTH / (float)(width + 2);
    size.y = WIN_HEIGHT / height * 0.2f;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            Vector2 pos;
            pos.x = x * size.x + size.x * 1.5f;
            pos.y = y * size.y + size.y * 1.5f;

            Brick* brick = new Brick(pos, size, y + 1);
            bricks.push_back(brick);
        }
    }
}

void BrickManager::ClearStage()
{
    for (Brick* brick : bricks)
        delete brick;

    bricks.clear();
}
