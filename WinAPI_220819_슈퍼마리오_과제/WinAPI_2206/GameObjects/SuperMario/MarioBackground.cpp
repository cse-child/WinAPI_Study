#include "Framework.h"

MarioBackground::MarioBackground()
{
    Texture* bgTexture = TEXTURE->Add(L"Textures/Mario_Bg.bmp", 1000, 600);

    bgs[0] = new ImageRect(bgTexture);
    bgs[0]->Pos() = { CENTER_X, CENTER_Y };
    bgs[0]->Size() = { WIN_WIDTH, WIN_HEIGHT };

    bgs[1] = new ImageRect(bgTexture);
    bgs[1]->Pos() = { CENTER_X + WIN_WIDTH, CENTER_Y };
    bgs[1]->Size() = { WIN_WIDTH, WIN_HEIGHT };
}

MarioBackground::~MarioBackground()
{
    delete bgs[0];
    delete bgs[1];
}

void MarioBackground::Update()
{
    for (ImageRect* bg : bgs)
    {
        bg->Pos().x -= speed * DELTA;

        if (bg->Right() <= 0)
        {
            bg->Pos().x += WIN_WIDTH * 2.0f;
        }
    }
}

void MarioBackground::Render(HDC hdc)
{
    for (ImageRect* bg : bgs)
        bg->Render(hdc);
}
