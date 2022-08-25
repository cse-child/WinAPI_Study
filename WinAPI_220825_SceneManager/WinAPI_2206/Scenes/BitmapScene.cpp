#include "Framework.h"
#include "BitmapScene.h"

BitmapScene::BitmapScene()
{
    //Timer::Get()->SetLockFPS(100);

    HDC hdc = GetDC(hWnd);
    memDC = CreateCompatibleDC(hdc);
    ReleaseDC(hWnd, hdc);

    bitmap = (HBITMAP)LoadImage(hInst, L"Textures/test.bmp",
        IMAGE_BITMAP, WIN_WIDTH, WIN_HEIGHT, LR_LOADFROMFILE);

    sivaBitmap = (HBITMAP)LoadImage(hInst, L"Textures/siva.bmp",
        IMAGE_BITMAP, 384, 94, LR_LOADFROMFILE);

    siva = new Siva();
}

BitmapScene::~BitmapScene()
{
    DeleteDC(memDC);
    DeleteObject(bitmap);

    delete siva;
}

void BitmapScene::Update()
{
    siva->Update();
}

void BitmapScene::Render(HDC hdc)
{
    SelectObject(memDC, bitmap);

    BitBlt(
        hdc,//(출력할 영역)어떤 DC에 복사할지?
        0, 0,//(출력할 위치)어느 위치에 복사할지?
        WIN_WIDTH, WIN_HEIGHT,//(출력할 크기)
        memDC,//(복사할 영역)어떤 DC에서 부터 복사할지?
        0, 0,//(복사할 위치)어디에서 부터 복사할지?
        SRCCOPY
    );

    //StretchBlt(
    //    hdc,
    //    0, 0,
    //    500, 500,
    //    memDC,
    //    150, 100,
    //    200, 100,
    //    SRCCOPY
    //);

    SelectObject(memDC, sivaBitmap);

    GdiTransparentBlt(
        hdc,
        CENTER_X, CENTER_Y,
        48, 47,
        memDC,
        48, 0,
        48, 47,
        MAGENTA
    );

    siva->Render(hdc);
}
