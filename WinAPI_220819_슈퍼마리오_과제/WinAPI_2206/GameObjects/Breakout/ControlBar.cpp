#include "Framework.h"

ControlBar::ControlBar()
{
    pos = { CENTER_X, WIN_HEIGHT * 0.9f };
    size = { 100, 20 };

    hBrush = CreateSolidBrush(RGB(100, 100, 100));
}

ControlBar::~ControlBar()
{
    DeleteObject(hBrush);
}

void ControlBar::Update()
{
    if (KEY_PRESS(VK_RIGHT))
    {
        pos.x += speed * DELTA;

        if (Right() > WIN_WIDTH)
            pos.x = WIN_WIDTH - Half().x;
    }

    if (KEY_PRESS(VK_LEFT))
    {
        pos.x -= speed * DELTA;

        if (Left() < 0)
            pos.x = Half().x;
    }
}

void ControlBar::Render(HDC hdc)
{
    SelectObject(hdc, hBrush);

    Rect::Render(hdc);
}
