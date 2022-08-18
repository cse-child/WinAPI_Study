#include "Framework.h"

Background::Background()
{
    Texture* bgTexture = TEXTURE->Add(L"Textures/CookieBG.bmp", 1009, 370);

    bgs[0] = new ImageRect(bgTexture);
    bgs[0]->Pos() = { CENTER_X, CENTER_Y };
    bgs[0]->Size() = { WIN_WIDTH, WIN_HEIGHT };

    bgs[1] = new ImageRect(bgTexture);
    bgs[1]->Pos() = { WIN_WIDTH + CENTER_X, CENTER_Y };
    bgs[1]->Size() = { WIN_WIDTH, WIN_HEIGHT };
}

Background::~Background()
{
    for (ImageRect* bg : bgs)
        delete bg;
}

void Background::Update()
{
    for (ImageRect* bg : bgs)
    {
        bg->Pos().x -= speed * DELTA;

        if (bg->Right() <= 0)
            bg->Pos().x += WIN_WIDTH * 2.0f;
    }
}

void Background::Render(HDC hdc)
{
    for (ImageRect* bg : bgs)
        bg->Render(hdc);
}
