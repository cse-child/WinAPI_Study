//#pragma once
//
//class PaintTool
//{
//public:
//	enum Menu
//	{
//		PAINT_LINE = 1,
//		PAINT_RECT,
//		PAINT_ELLIP,
//		PAINT_PEN
//	};
//public:
//	PaintTool(HWND hWnd);
//	~PaintTool();
//	void MouseMove(POINT mousePos);
//	void SetSelectPen(HPEN pen);
//
//private:
//	HDC hdc;
//	POINT mousePos;
//	POINT startClickPos;
//	Menu selectMenu;
//	bool isStart = false;
//	HPEN selectPen;
//};