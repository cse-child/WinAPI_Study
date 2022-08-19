#include "Framework.h"

Siva::Siva()
{
    HDC hdc = GetDC(hWnd);
    memDC = CreateCompatibleDC(hdc);
    ReleaseDC(hWnd, hdc);

    hbitmap = (HBITMAP)LoadImage(hInst, L"Textures/siva.bmp",
        IMAGE_BITMAP, 384, 94, LR_LOADFROMFILE);

    imageSize = { 384, 94 };
    imageFrame = { 8, 2 };
    cutSize.x = imageSize.x / imageFrame.x;
    cutSize.y = imageSize.y / imageFrame.y;

    size = cutSize;
    pos = { CENTER_X, CENTER_Y };
}

Siva::~Siva()
{
    DeleteDC(memDC);
    DeleteObject(hbitmap);
}

void Siva::Update()
{
    Animation();
    
    Move();
    Jump();
}

void Siva::Render(HDC hdc)
{
    SelectObject(memDC, hbitmap);

    GdiTransparentBlt(
        hdc,
        (int)Left(), (int)Top(),
        (int)size.x, (int)size.y,
        memDC,
        cutSize.x * curFrame.x, cutSize.y * curFrame.y,
        cutSize.x, cutSize.y,
        MAGENTA
    );
}

void Siva::Animation()
{
    time += DELTA;

    if (time > 0.1f)
    {
        time -= 0.1f;

        curFrame.x = (++curFrame.x) % 6 + 2;
    }
}

void Siva::Move()
{
    if (KEY_PRESS('D'))
    {
        pos.x += speed * DELTA;
        curFrame.y = 0;
    }

    if (KEY_PRESS('A'))
    {
        pos.x -= speed * DELTA;
        curFrame.y = 1;
    }
}

void Siva::Jump()
{
    if (KEY_DOWN(VK_LBUTTON))
        jumpVelocity = JUMP_POWER;

    jumpVelocity -= GRAVITY * DELTA;

    pos.y -= jumpVelocity * DELTA;
}
