#include "framework.h"

PaintTool::PaintTool(HWND hWnd) : hWnd(hWnd)
{
	hdc = GetDC(hWnd);

	SetColors();
	CreatePensAndBrushes();
}

PaintTool::~PaintTool()
{
}

void PaintTool::MouseKeyDown()
{
	switch (selectShape)
	{
	case PaintTool::Shape::POINT:
		DrawPoint();
		break;
	case PaintTool::Shape::LINE:
	case PaintTool::Shape::RECT:
	case PaintTool::Shape::ELLIPSE:
	case PaintTool::Shape::PEN:
		startMousePos = curMousePos;
		break;
	}
	isMouseDown = true;
}

void PaintTool::MouseKeyUp()
{
	SelectObject(hdc, pens[(int)selectColor]);
	SelectObject(hdc, brushes[(int)selectColor]);

	switch (selectShape)
	{
	case PaintTool::Shape::LINE:
		MoveToEx(hdc, startMousePos.x, startMousePos.y, nullptr);
		LineTo(hdc, curMousePos.x, curMousePos.y);
		break;
	case PaintTool::Shape::RECT:
		Rectangle(hdc, startMousePos.x, startMousePos.y,
			curMousePos.x, curMousePos.y);
		break;
	case PaintTool::Shape::ELLIPSE:
		Ellipse(hdc, startMousePos.x, startMousePos.y,
			curMousePos.x, curMousePos.y);
		break;
	}
	isMouseDown = false;
}

void PaintTool::MouseKeyPress()
{
	if (!isMouseDown) return;
	if (selectShape != Shape::PEN) return;

	SelectObject(hdc, pens[(int)selectColor]);

	MoveToEx(hdc, startMousePos.x, startMousePos.y, nullptr);
	LineTo(hdc, curMousePos.x, curMousePos.y);

	startMousePos = curMousePos;
}

void PaintTool::SetMousePos(LPARAM lParam)
{
	curMousePos.x = LOWORD(lParam);
	curMousePos.y = HIWORD(lParam);
}

void PaintTool::ShowInfo()
{
	wstring str = L"X : " + to_wstring(curMousePos.x);
	str += L", Y : " + to_wstring(curMousePos.y)+L"  ";

	SetTextColor(hdc, colors[0]);
	TextOut(hdc, 0, 0, str.c_str(), str.length());

	switch (selectColor)
	{
	case PaintTool::Color::BLACK:
		str = L"Select Color : BLACK   ";
		break;
	case PaintTool::Color::RED:
		str = L"Select Color : RED     ";
		break;
	case PaintTool::Color::GREEN:
		str = L"Select Color : GREEN   ";
		break;
	case PaintTool::Color::BLUE:
		str = L"Select Color : BLUE    ";
		break;
	}
	SetTextColor(hdc, colors[(int)selectColor]);
	TextOut(hdc, 0, 20, str.c_str(), str.length());

	switch (selectShape)
	{
	case PaintTool::Shape::POINT:
		str = L"Select Shape : POINT   ";
		break;
	case PaintTool::Shape::LINE:
		str = L"Select Shape : LINE    ";
		break;
	case PaintTool::Shape::RECT:
		str = L"Select Shape : RECT     ";
		break;
	case PaintTool::Shape::ELLIPSE:
		str = L"Select Shape : ELLIPSE";
		break;
	case PaintTool::Shape::PEN:
		str = L"Select Shape : PEN       ";
		break;
	}
	SetTextColor(hdc, RGB(255, 128, 0));
	TextOut(hdc, 0, 40, str.c_str(), str.length());
}

void PaintTool::DrawPoint()
{
	SetPixel(hdc, curMousePos.x, curMousePos.y, colors[(int)selectColor]);
	//switch (selectColor)
	//{
	//case PaintTool::Color::BLACK:
	//	SetPixel(hdc, curMousePos.x, curMousePos.y, RGB(0, 0, 0));
	//	break;
	//case PaintTool::Color::RED:
	//	SetPixel(hdc, curMousePos.x, curMousePos.y, RGB(255, 0, 0));
	//	break;
	//case PaintTool::Color::GREEN:
	//	SetPixel(hdc, curMousePos.x, curMousePos.y, RGB(0, 255, 0));
	//	break;
	//case PaintTool::Color::BLUE:
	//	SetPixel(hdc, curMousePos.x, curMousePos.y, RGB(0, 0, 255));
	//	break;
	//}
}

void PaintTool::InputKey(WPARAM wParam)
{
	switch (wParam)
	{
	case '1':
		selectColor = Color::BLACK;
		break;
	case '2':
		selectColor = Color::RED;
		break;
	case '3':
		selectColor = Color::GREEN;
		break;
	case '4':
		selectColor = Color::BLUE;
		break;
	case VK_F1:
		selectShape = Shape::POINT;
		break;
	case VK_F2:
		selectShape = Shape::LINE;
		break;
	case VK_F3:
		selectShape = Shape::RECT;
		break;
	case VK_F4:
		selectShape = Shape::ELLIPSE;
		break;
	case VK_F5:
		selectShape = Shape::PEN;
		break;
	case VK_ESCAPE:
		Clear();
		break;
	}
	ShowInfo();
}

void PaintTool::CreatePensAndBrushes()
{
	for (int i = 0; i < (int)Color::MAX; i++)
	{
		pens[i] = CreatePen(PS_SOLID, 3, colors[i]);
		brushes[i] = CreateSolidBrush(colors[i]);
	}
}

void PaintTool::Clear()
{
	InvalidateRect(hWnd, nullptr, TRUE);
}

void PaintTool::SetColors()
{
	colors[(int)Color::BLACK] = RGB(0, 0, 0);
	colors[(int)Color::RED] = RGB(255, 0, 0);
	colors[(int)Color::GREEN] = RGB(0, 255, 0);
	colors[(int)Color::BLUE] = RGB(0, 0, 255);
}
