#include "Framework.h"

Brick::Brick(Vector2 pos, Vector2 size, int hp)
    : Rect(pos, size), hp(hp)
{
    hBrushes.resize(MAX_HP);

    hBrushes[0] = CreateSolidBrush(RED);
    hBrushes[1] = CreateSolidBrush(YELLOW);
    hBrushes[2] = CreateSolidBrush(BLUE);
    hBrushes[3] = CreateSolidBrush(GREEN);    
}

Brick::~Brick()
{
    for (HBRUSH brush : hBrushes)
        DeleteObject(brush);

    hBrushes.clear();
}

void Brick::Render(HDC hdc)
{
    if (hp <= 0)
        return;

    SelectObject(hdc, hBrushes[hp - 1]);
    Rect::Render(hdc);
}

Direction Brick::Collision(Circle * circle)
{
    if (hp <= 0) return Direction::NONE;

    if (!IsCollision(circle)) return Direction::NONE;
    
    hp--;

    Rect rect(circle->Pos(), { circle->Radius() * 2, circle->Radius() * 2 });

    Vector2 overlapSize;
    IsCollision(&rect, overlapSize);

    if (overlapSize.x > overlapSize.y)//상하충돌
    {
        if (pos.y > circle->Pos().y)
        {
            return Direction::UP;
        }
        else
        {
            return Direction::DOWN;
        }
    }
    else//좌우 충돌
    {
        if (pos.x > circle->Pos().x)
        {
            return Direction::LEFT;
        }
        else
        {
            return Direction::RIGHT;
        }
    }
}
