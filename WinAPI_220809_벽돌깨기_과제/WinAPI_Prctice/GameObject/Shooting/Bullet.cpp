#include "Framework.h"

Bullet::Bullet(HBRUSH brush) 
	: Circle({0, 0}, 20), brush(brush)
{
	isActive = false;
	//brush = CreateSolidBrush(RGB(100, 100, 100));
}

Bullet::~Bullet()
{
	//DeleteObject(brush); // °´Ã¼º° Delete ¹æ¹ý Á¤¸®
}

void Bullet::Update()
{
	if (!isActive)
		return;
	
	pos += direction * speed;

	/* ºÎµúÈú¶§ Æ¨°Ü³ª°¡±â */
	if (pos.x - radius < 0.0f || pos.x + radius > WIN_WIDTH)
		direction.x *= -1.0f;

	if (pos.y - radius < 0.0f || pos.y + radius > WIN_HEIGHT)
		direction.y *= -1.0f;

	if (pos.y > WIN_HEIGHT - radius)
	{
		GameManager::Get()->Stop();

		MessageBox(GameManager::Get()->GetHWND(),
			L"GameOver", L"Result", MB_OK);

		PostQuitMessage(0);
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

