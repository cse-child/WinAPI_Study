#include "Framework.h"

Brick::Brick(Vector2 pos, Vector2 size, int hp)
    :Rect(pos, size), hp(hp)
{
    hBrushes.resize(MAX_HP);

    hBrushes[0] = CreateSolidBrush(MAGENTA);
    hBrushes[1] = CreateSolidBrush(YELLOW);
    hBrushes[2] = CreateSolidBrush(CYAN);
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

Direction Brick::Collision(Circle* circle)
{
    if (hp <= 0) return Direction::NONE;

    if (!IsCollision(circle)) return Direction::NONE;

    hp--;
    if (hp <= 0)
        BrickManager::Get()->DecreaseBrickCount();

    Rect rect(circle->Pos(), { circle->Radius() * 2, circle->Radius() * 2 });
    
    Vector2 overlapSize;
    IsCollision(&rect, overlapSize);

    if (overlapSize.x > overlapSize.y) // 상하충돌
    {
        if (pos.y > circle->Pos().y) 
        {
            return Direction::UP; // 공 기준: 블록 위에서 충돌
        }
        else
        {
            return Direction::DOWN;
        }
    }
    else // 좌우충돌
    {
        if (pos.x > circle->Pos().x)
        {
            return Direction::LEFT; // 공이 블록 왼쪽에서 충돌
        }
        else
        {
            return Direction::RIGHT;
        }
    }


}
