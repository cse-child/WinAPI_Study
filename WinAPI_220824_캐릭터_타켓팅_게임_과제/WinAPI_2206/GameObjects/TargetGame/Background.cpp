#include "Framework.h"

Background::Background()
{
	Texture* texture = TEXTURE->Add(L"Textures/Map_Background.bmp", 1626, 558);

	bgs[0] = new ImageRect(texture);
    bgs[0]->Pos() = { CENTER_X, CENTER_Y };
    bgs[0]->Size() = { WIN_WIDTH, WIN_HEIGHT };

    bgs[1] = new ImageRect(texture);
    bgs[1]->Pos() = { CENTER_X + WIN_WIDTH, CENTER_Y };
    bgs[1]->Size() = { WIN_WIDTH, WIN_HEIGHT };
}

Background::~Background()
{
    delete bgs[0];
    delete bgs[1];
}

void Background::Update()
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

void Background::Render(HDC hdc)
{
    for (ImageRect* bg : bgs)
        bg->Render(hdc);
}
