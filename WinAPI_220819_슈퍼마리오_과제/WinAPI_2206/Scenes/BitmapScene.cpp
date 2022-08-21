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
        hdc,//(����� ����)� DC�� ��������?
        0, 0,//(����� ��ġ)��� ��ġ�� ��������?
        WIN_WIDTH, WIN_HEIGHT,//(����� ũ��)
        memDC,//(������ ����)� DC���� ���� ��������?
        0, 0,//(������ ��ġ)��𿡼� ���� ��������?
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
