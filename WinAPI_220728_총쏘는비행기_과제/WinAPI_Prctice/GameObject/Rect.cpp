#include "Framework.h"

Rect::Rect(POINT startPos, POINT endPos)
	:startPos(startPos), endPos(endPos)
{
}

Rect::~Rect()
{
}

void Rect::Render(HDC hdc)
{
	SelectObject(hdc, brush);
	Rectangle(hdc, startPos.x, startPos.y, endPos.x, endPos.y);
}
