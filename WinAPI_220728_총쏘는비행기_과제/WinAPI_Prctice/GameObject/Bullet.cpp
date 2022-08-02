#include "Framework.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (!isActive) return;

	lifeTime++;

	if (lifeTime >= safeTime)
		isActive = false;
}

void Bullet::Render(HDC hdc)
{
	if (!isActive) return;

	Ellipse(hdc, pos.x, pos.y, pos.x + 10, pos.y + 20);

	for (int i = pos.y; i >= 0; i--) // �� �߻�Ǵ� �κ� �����ϱ�
	{
		pos.y -= 10;
	}
}

void Bullet::Shoot()
{
	isActive = true;

	safeTime = MAX_LIFE_TIME;
	lifeTime = 0;
}

void Bullet::SetBulletPos(POINT pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
}
