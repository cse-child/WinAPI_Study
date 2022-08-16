#include "Framework.h"
#include "BitmapScene.h"

BitmapScene::BitmapScene()
{
	Timer::Get()->SetLockFPS(100);

	HDC hdc = GetDC(hWnd);
	memDC = CreateCompatibleDC(hdc);
	ReleaseDC(hWnd, hdc);
	
	//bitmap = (HBITMAP)LoadImage(hInst, L"Textures/test.bmp",
	//	IMAGE_BITMAP, 750, 921, LR_LOADFROMFILE);

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

	/* ���� ���������� Ư�� ��ġ������ ���� */
	BitBlt
	( hdc, // (����� ����) � DC�� ��������?
		0, 0, // (����� ��ġ) ��� ��ġ�� ��������?
		WIN_WIDTH, WIN_HEIGHT, // (����� ũ��)
		memDC, // (������ ����) � DC���� ���� ��������?
		0,0, // (������ ��ġ) ��𿡼� ���� ��������?
		SRCCOPY
	);

	/* ���ϴ� Ư�� ��ġ�� �̹����� ���� */
	//StretchBlt(
	//	hdc, // ���, �����ġ��?
	//	0, 0,
	//	500, 500,
	//	memDC,
	//	150, 200,
	//	200, 100,
	//	SRCCOPY
	//);

	SelectObject(memDC, sivaBitmap);

	/* �̹����� �޹���� �����ϰ� ó���ϴ� �Լ� */
	GdiTransparentBlt(
		hdc,
		CENTER_X, CENTER_Y,
		48, 47, // ������ ������� 384/2, 94/2
		memDC,
		48, 0,
		48, 47,
		MAGENTA // ���� ��� ��
	);

	siva->Render(hdc);

}
