#include "Framework.h"

Bullet::Bullet(HBRUSH brush) 
	: Circle({0, 0}, 20), brush(brush)
{
	//brush = CreateSolidBrush(RGB(100, 100, 100));
}

Bullet::~Bullet()
{
	//DeleteObject(brush); // 객체별 Delete 방법 정리
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

	pos.y -= speed;

	if (pos.y < radius)
	{
		isActive = false;

		BulletManager::Get()->IncreaseCount();
	}
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

