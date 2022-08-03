#include "Framework.h"

Rect::Rect(POINT pos, UINT area)
    :area(area)
{
    this->pos = pos;
}

Rect::~Rect()
{
}

void Rect::Render(HDC hdc)
{
    if (!isActive) return;

    SelectObject(hdc, brush);
    Rectangle(hdc, pos.x - (area / 2), pos.y - (area / 2), pos.x + (area / 2), pos.y + (area / 2));
}

bool Rect::IsCollision(POINT pos)
{
    POINT startPos = { this->pos.x - (area / 2), this->pos.y - (area / 2) };
    POINT endPos = { this->pos.x + (area / 2), this->pos.y + (area / 2) };
   
    if (pos.x >= startPos.x && pos.x <= endPos.x &&
        pos.y >= startPos.y && pos.y <= endPos.y)
        return true;
    return false;
}
