#include "Framework.h"

Bullet::Bullet(HBRUSH brush) 
	: Circle({0, 0}, 20), brush(brush)
{
	isActive = false;
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

	//pos.x += cosf(angle) * speed;
	//pos.y += -sinf(angle) * speed;
	
	pos += direction * speed;

	/* 화면 밖으로 가면 사라지기 */
	//if (pos.x + radius < 0.0f || pos.x - radius > WIN_WIDTH)
	//	isActive = false;
	//
	//if (pos.y + radius < 0.0f || pos.y - radius > WIN_HEIGHT)
	//	isActive = false;

	/* 부딪힐때 튕겨나가기 */
	if (pos.x - radius < 0.0f || pos.x + radius > WIN_WIDTH)
		direction.x *= -1.0f;

	if (pos.y - radius < 0.0f || pos.y + radius > WIN_HEIGHT)
		direction.y *= -1.0f;


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

