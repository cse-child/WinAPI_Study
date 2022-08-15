#include "Framework.h"

PipeManager::PipeManager()
{
    Texture* upPipeTexture = new Texture(L"Textures/pipeup.bmp", 26, 162);
    Texture* downPipeTexture = new Texture(L"Textures/pipedown.bmp", 26, 162);

    upPipes.resize(PIPE_NUM);
    downPipes.resize(PIPE_NUM);

    for (UINT i = 0; i < PIPE_NUM; i++)
    {
        upPipes[i] = new ImageRect(upPipeTexture);
        downPipes[i] = new ImageRect(downPipeTexture);

        upPipes[i]->Pos().x = WIN_WIDTH + interval.x * i;
        downPipes[i]->Pos().x = WIN_WIDTH + interval.x * i;

        upPipes[i]->Size() *= 3;
        downPipes[i]->Size() *= 3;

        upPipes[i]->Pos().y = Random(MIN_PIPE_HEIGHT, MAX_PIPE_HEIGHT);
        downPipes[i]->Pos().y = upPipes[i]->Pos().y + interval.y + upPipes[i]->Size().y;
    }
}

PipeManager::~PipeManager()
{
    for (UINT i = 0; i < PIPE_NUM; i++)
    {
        delete upPipes[i];
        delete downPipes[i];
    }

    upPipes.clear();
    downPipes.clear();
}

void PipeManager::Update()
{
    for (UINT i = 0; i < PIPE_NUM; i++)
    {
        upPipes[i]->Pos().x -= speed * DELTA;
        downPipes[i]->Pos().x -= speed * DELTA;

        if (upPipes[i]->Right() <= 0)
        {
            upPipes[i]->Pos().x += (upPipes[i]->Half().x + interval.x) * (PIPE_NUM - 2);
            downPipes[i]->Pos().x += (upPipes[i]->Half().x + interval.x) * (PIPE_NUM - 2);

            upPipes[i]->Pos().y = Random(MIN_PIPE_HEIGHT, MAX_PIPE_HEIGHT);
            downPipes[i]->Pos().y = upPipes[i]->Pos().y + interval.y + upPipes[i]->Size().y;
        }
    }
}

void PipeManager::Render(HDC hdc)
{
    for (UINT i = 0; i < PIPE_NUM; i++)
    {
        upPipes[i]->Render(hdc);
        downPipes[i]->Render(hdc);
    }
}

bool PipeManager::IsCollision(Rect* rect)
{
    for (UINT i = 0; i < PIPE_NUM; i++)
    {
        if (upPipes[i]->IsCollision(rect))
            return true;

        if (downPipes[i]->IsCollision(rect))
            return true;
    }
    return false;
}
