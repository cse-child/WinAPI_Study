#include "Framework.h"

bool Texture::isDebugMode = false;

Texture::Texture(wstring imageFile, int widthSize, int heightSize, COLORREF transColor)
	:transColor(transColor)
{
	CreateBitmap(imageFile, widthSize, heightSize);

	imageFrame = { 1,1 };
	cutSize = imageSize;
}

Texture::Texture(wstring imageFile, int widthSize, int heightSize, int widthFrame, int heightFrame, COLORREF transColor)
	:transColor(transColor)
{
	CreateBitmap(imageFile, widthSize, heightSize);

	imageFrame = { widthFrame, heightFrame };
	cutSize = { widthSize / widthFrame, heightSize / heightFrame };
}

Texture::~Texture()
{
	DeleteDC(memDC);
	DeleteObject(hbitmap);
}

void Texture::Render(HDC hdc, Rect* rect, POINT curFrame)
{
	if (isDebugMode)
		rect->LineRender(hdc);

	GdiTransparentBlt(
		hdc,
		(int)(rect->Left()), (int)(rect->Top()),
		(int)(rect->Size().x), (int)(rect->Size().y),
		memDC,
		cutSize.x * curFrame.x, cutSize.y * curFrame.y,
		cutSize.x, cutSize.y,
		transColor
	);
}

void Texture::CreateBitmap(wstring imageFile, int widthSize, int heightSize)
{
	HDC hdc = GetDC(hWnd);
	memDC = CreateCompatibleDC(hdc);
	ReleaseDC(hWnd, hdc);

	hbitmap = (HBITMAP)LoadImage(hInst, imageFile.c_str(), IMAGE_BITMAP,
		widthSize, heightSize, LR_LOADFROMFILE);

	SelectObject(memDC, hbitmap);

	imageSize = { widthSize, heightSize };
}
