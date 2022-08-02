#include "Framework.h"

Line::Line(POINT startPos, POINT endPos)
	:startPos(startPos), endPos(endPos)
{
}

Line::~Line()
{
}

void Line::Render(HDC hdc)
{
	MoveToEx(hdc, startPos.x, startPos.y, nullptr);
	LineTo(hdc, endPos.x, endPos.y);
}
