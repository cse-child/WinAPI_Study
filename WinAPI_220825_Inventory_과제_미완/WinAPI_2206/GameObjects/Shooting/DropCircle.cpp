#include "Framework.h"
#include "DropCircle.h"

DropCircle::DropCircle()
{
    isActive = false;
}

DropCircle::~DropCircle()
{
}

void DropCircle::Update()
{
    if (!isActive) return;

    Move();
    Collision();    
}

void DropCircle::Render(HDC hdc)
{
    if (brush)
    {
        SelectObject(hdc, brush);
    }

    Circle::Render(hdc);

    Vector2 frontPos;
    frontPos.x = pos.x + cosf(angle) * radius;
    frontPos.y = pos.y - sinf(angle) * radius;

    MoveToEx(hdc, pos.x, pos.y, nullptr);
    LineTo(hdc, frontPos.x, frontPos.y);
}

void DropCircle::InitCircle()
{
    isActive = true;

    radius = Random(MIN_RADIUS, MAX_RADIUS);
    speed = Random(MIN_SPEED, MAX_SPEED);    

    int random = Random(0, 4);

    switch (random)
    {
    case 0:
        pos.x = Random(radius, WIN_WIDTH - radius);
        pos.y = -radius;
        break;
    case 1:
        pos.x = Random(radius, WIN_WIDTH - radius);
        pos.y = WIN_HEIGHT + radius;
        break;
    case 2:
        pos.x = -radius;
        pos.y = Random(radius, WIN_HEIGHT - radius);
        break;
    case 3:
        pos.x = WIN_WIDTH + radius;
        pos.y = Random(radius, WIN_HEIGHT - radius);
        break;
    default:
        break;
    }

    direction = (target->Pos() - pos).Normalized();
    angle = direction.Angle();
}

void DropCircle::Move()
{
    //pos.y += speed;

    Vector2 temp = target->Pos() - pos;

    //if (angle < temp.Angle())
    //    angle += rotSpeed;
    //else if (angle > temp.Angle())
    //    angle -= rotSpeed;

    direction = { cosf(angle), -sinf(angle) };

    if (Vector2::Cross(temp, direction) > 0)
        angle -= rotSpeed;
    else if (Vector2::Cross(temp, direction) < 0)
        angle += rotSpeed;

    pos += direction * speed;

    if (pos.x + radius < 0.0f || pos.x - radius > WIN_WIDTH)
        isActive = false;
    
    if (pos.y + radius < 0.0f || pos.y - radius > WIN_HEIGHT)
        isActive = false;
}

void DropCircle::Collision()
{
    if (GetAsyncKeyState(VK_LBUTTON))
    {
        if (IsCollision(mousePos))
        {
            isActive = false;
        }
    }
}
