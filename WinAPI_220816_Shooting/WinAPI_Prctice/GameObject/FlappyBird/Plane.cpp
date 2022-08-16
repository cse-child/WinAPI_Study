#include "Framework.h"

Plane::Plane()
{
	texture = TEXTURE->Add(L"Textures/Plane.bmp", 886, 302, 2, 1);
	pos = { WIN_WIDTH * 0.2f, CENTER_Y };
	size = texture->GetSize() * 0.5f;
}

Plane::~Plane()
{
}

void Plane::Update()
{
	Animation();
	Move();
	Fire();
}

void Plane::Render(HDC hdc)
{
	ImageRect::Render(hdc, { curFrame, 0 });
}

void Plane::Animation()
{
	time += DELTA;
	if (time > 0.1f)
	{
		time -= 0.1f;
		curFrame = ++curFrame % 2;
	}
}

void Plane::Jump()
{
	if (KEY_DOWN(VK_SPACE))
		jumpVelocity = JUMP_POWER;

	jumpVelocity -= GRAVITY * DELTA;

	pos.y -= jumpVelocity * DELTA;
}

void Plane::Move()
{
	if (KEY_PRESS(VK_RIGHT))
		pos.x += speed * DELTA;
	if (KEY_PRESS(VK_LEFT))
		pos.x -= speed * DELTA;
	if (KEY_PRESS(VK_UP))
		pos.y -= speed * DELTA;
	if (KEY_PRESS(VK_DOWN))
		pos.y += speed * DELTA;
}

void Plane::Fire()
{
	if (KEY_DOWN(VK_SPACE))
	{
		firePos.x = Right();
		firePos.y = pos.y;

		BulletManager::Get()->Fire("Plane", firePos, Vector2(1, 0));
	}
}
