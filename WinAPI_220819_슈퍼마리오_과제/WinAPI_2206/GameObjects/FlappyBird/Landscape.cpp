#include "Framework.h"

Landscape::Landscape()
{    
    Texture * bgTexture = TEXTURE->Add(L"Textures/BG.bmp", 1460, 1095);

    bgs[0] = new ImageRect(bgTexture);
    bgs[0]->Pos() = {CENTER_X, CENTER_Y};
    bgs[0]->Size() = {WIN_WIDTH, WIN_HEIGHT};

    bgs[1] = new ImageRect(bgTexture);
    bgs[1]->Pos() = { CENTER_X + WIN_WIDTH, CENTER_Y };
    bgs[1]->Size() = { WIN_WIDTH, WIN_HEIGHT };
}

Landscape::~Landscape()
{
    delete bgs[0];
    delete bgs[1];
}

void Landscape::Update()
{
    for (ImageRect * bg : bgs)
    {
        bg->Pos().x -= speed * DELTA;

        if (bg->Right() <= 0)
        {
            bg->Pos().x += WIN_WIDTH * 2.0f;
        }
    }
}

void Landscape::Render(HDC hdc)
{
    for (ImageRect * bg : bgs)
        bg->Render(hdc);
}
