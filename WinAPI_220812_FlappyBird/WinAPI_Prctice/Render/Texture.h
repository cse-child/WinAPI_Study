#pragma once

class Texture
{
public:
	Texture(wstring imageFile, int widthSize, int heightSize, 
		COLORREF transColor = MAGENTA);
	Texture(wstring imageFile, int widthSize, int heightSize, 
		int widthFrame, int heightFrame, COLORREF transColor = MAGENTA);
	~Texture();

	void Render(HDC hdc, class Rect* rect, POINT curFrame = { 0, 0 });

	Vector2 GetSize() { return Vector2(cutSize); }

	static void SwichDebug() { isDebugMode = !isDebugMode; }

private:
	void CreateBitmap(wstring imageFile, int widthSize, int heightSize);

private:
	HDC memDC;
	HBITMAP hbitmap;

	COLORREF transColor;

protected:
	POINT imageSize;
	POINT imageFrame;
	POINT cutSize;

	static bool isDebugMode;
};