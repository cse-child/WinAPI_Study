#include "Framework.h"

Ball::Ball() : direction(1, -1)
{
    radius = 10;

    direction = direction.Normalized();

    hBrush = CreateSolidBrush(BLACK);
}

Ball::~Ball()
{
    DeleteObject(hBrush);
}

void Ball::Update()
{
    if (KEY_DOWN(VK_SPACE))
        isPlay = true;

    Move();

    CollisionBorder();
    CollisionBar();
    CollisionBrick();
}

void Ball::Render(HDC hdc)
{
    SelectObject(hdc, hBrush);

    Circle::Render(hdc);
}

void Ball::Move()
{
    if (isPlay)
    {
        pos += direction * speed * DELTA;
    }
    else
    {
        pos.x = barRect->Pos().x;
        pos.y = barRect->Top() - radius;
    }
}

void Ball::CollisionBorder()
{
    if (pos.x + radius > WIN_WIDTH)
    {
        direction.x *= -1.0f;
        pos.x = WIN_WIDTH - radius;
    }
    else if (pos.x - radius < 0)
    {
        direction.x *= -1.0f;
        pos.x = radius;
    }

    if (pos.y - radius < 0)
    {
        direction.y *= -1.0f;
        pos.y = radius;
    }
    else if (pos.y + radius > WIN_HEIGHT)
    {
        isPlay = false;
        direction = { 0, -1 };
        barRect->Pos().x = CENTER_X;
    }
}

void Ball::CollisionBar()
{
    if (!barRect->IsCollision(this)) return;

    direction = (pos - barRect->Pos()).Normalized();
}

void Ball::CollisionBrick()
{
    Direction result = BrickManager::Get()->Collision(this);

    switch (result)
    {
    case GameMath::Direction::LEFT:        
    case GameMath::Direction::RIGHT:
        direction.x *= -1.0f;
        break;
    case GameMath::Direction::UP:        
    case GameMath::Direction::DOWN:
        direction.y *= -1.0f;
        break;    
    }
}
