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

    wstring str = L"Brick Count : " + to_wstring(totalBrick);
    TextOut(hdc, CENTER_X, 0, str.c_str(), str.length());
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
    int width = 1;
    int height = 4;
    totalBrick = width * height;

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

void BrickManager::CreateStage2()
{
    bricks.clear();
    ball->Init();

    int width = 5;
    int height = 4;
    totalBrick = width * height;

    Vector2 size;
    size.x = WIN_WIDTH / (float)(width + 2);
    size.y = WIN_HEIGHT / height * 0.2f;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            Vector2 pos;
            pos.x = x * size.x + size.x * 1.5f *(x*0.3) +50.0f;
            pos.y = y * size.y + size.y * 1.5f + 100.0f;

            Brick* brick = new Brick(pos, size, Random(1,height+1));
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

void BrickManager::DecreaseBrickCount()
{
    --totalBrick;

    if (totalBrick <= 0 && !stage1Clear)
    {
        stage1Clear = true;
        CreateStage2();
    }
    else if (totalBrick <= 0 && stage1Clear)
    {
        GameManager::Get()->Stop();

        MessageBox(GameManager::Get()->GetHWND(),
            L"GameClear!", L"GameClear", MB_OK);

        PostQuitMessage(0);
    }
}
