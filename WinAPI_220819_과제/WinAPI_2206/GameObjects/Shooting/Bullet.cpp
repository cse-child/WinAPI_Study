#include "Framework.h"

Bullet::Bullet(Texture * texture)
    : ImageRect(texture)
{
    isActive = false;
}

Bullet::~Bullet()
{    
}

void Bullet::Update()
{
    if (!isActive) return;

    if (GetAsyncKeyState(VK_LBUTTON))
    {
        if (IsCollision(mousePos))
        {
            isActive = false;
        }
    }

    pos += direction * speed * DELTA;

    if (Right() < 0.0f || Left() > WIN_WIDTH)
        isActive = false;
            

    if (Bottom() < 0.0f || Top() > WIN_HEIGHT)
        isActive = false;
    
}

void Bullet::Render(HDC hdc)
{
    if (!isActive) return;

    texture->Render(hdc, this);
}

void Bullet::Fire(Vector2 pos)
{
    isActive = true;

    this->pos = pos;
}

void Bullet::Fire(Vector2 pos, float angle)
{
    isActive = true;

    this->pos = pos;
    this->angle = angle;
}

void Bullet::Fire(Vector2 pos, Vector2 direction)
{
    isActive = true;

    this->pos = pos;
    this->direction = direction;
}


