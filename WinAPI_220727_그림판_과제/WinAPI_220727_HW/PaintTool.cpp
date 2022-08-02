//#include "framework.h"
//
//PaintTool::PaintTool(HWND hWnd)
//{
//	hdc = GetDC(hWnd);
//}
//
//PaintTool::~PaintTool()
//{
//
//}
//
//void PaintTool::MouseMove(POINT mousePos)
//{
//	if (selectMenu == PAINT_PEN && isStart)
//	{
//		//HDC hdc = GetDC(hWnd);
//		SelectObject(hdc, selectPen);
//
//		MoveToEx(hdc, mousePos.x, mousePos.y, nullptr);
//		mousePos.x = LOWORD(lParam);
//		mousePos.y = HIWORD(lParam);
//		LineTo(hdc, mousePos.x, mousePos.y);
//
//		ReleaseDC(hWnd, hdc);
//	}
//	else
//	{
//		mousePos.x = LOWORD(lParam);
//		mousePos.y = HIWORD(lParam);
//	}
//}
//
//void PaintTool::SetSelectPen(HPEN pen)
//{
//	selectPen = pen;
//}
