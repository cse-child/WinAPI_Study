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

	/* 사진 시작점부터 특정 위치까지를 복사 */
	BitBlt
	( hdc, // (출력할 영역) 어떤 DC에 복사할지?
		0, 0, // (출력할 위치) 어느 위치에 복사할지?
		WIN_WIDTH, WIN_HEIGHT, // (출력할 크기)
		memDC, // (복사할 영역) 어떤 DC에서 부터 복사할지?
		0,0, // (복사할 위치) 어디에서 부터 복사할지?
		SRCCOPY
	);

	/* 원하는 특정 위치의 이미지를 복사 */
	//StretchBlt(
	//	hdc, // 어디에, 어느위치에?
	//	0, 0,
	//	500, 500,
	//	memDC,
	//	150, 200,
	//	200, 100,
	//	SRCCOPY
	//);

	SelectObject(memDC, sivaBitmap);

	/* 이미지의 뒷배경을 투명하게 처리하는 함수 */
	GdiTransparentBlt(
		hdc,
		CENTER_X, CENTER_Y,
		48, 47, // 프레임 개수대로 384/2, 94/2
		memDC,
		48, 0,
		48, 47,
		MAGENTA // 지울 배경 색
	);

	siva->Render(hdc);

}
