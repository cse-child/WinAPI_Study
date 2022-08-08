#include "Framework.h"

Bullet::Bullet(HBRUSH brush) 
	: Circle({0, 0}, 20), brush(brush)
{
	isActive = false;
	//brush = CreateSolidBrush(RGB(100, 100, 100));
}

Bullet::~Bullet()
{
	//DeleteObject(brush); // 按眉喊 Delete 规过 沥府
}

void Bullet::Update()
{
	if (!isActive)
		return;

	if (GetAsyncKeyState(VK_LBUTTON))
	{
		if (IsCollision(mousePos))
		{
			isActive = false;
		}
	}

	//pos.x += cosf(angle) * speed;
	//pos.y += -sinf(angle) * speed;
	
	pos += direction * speed;

	if (pos.x + radius < 0.0f || pos.x - radius > WIN_WIDTH)
		isActive = false;

	if (pos.y + radius < 0.0f || pos.y - radius > WIN_HEIGHT)
		isActive = false;
}

void Bullet::Render(HDC hdc)
{
	if (!isActive)
		return;

	SelectObject(hdc, brush);
	Circle::Render(hdc);
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

