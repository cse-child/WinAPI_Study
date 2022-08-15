#include "Framework.h"

Plane::Plane()
{
	texture = new Texture(L"Textures/Plane.bmp", 886, 302, 2, 1);
	pos = { WIN_WIDTH * 0.2f, CENTER_Y };
	size = texture->GetSize() * 0.5f;
}

Plane::~Plane()
{
}

void Plane::Update()
{
	time += DELTA;
	if (time > 0.1f)
	{
		time -= 0.1f;
		curFrame = ++curFrame % 2;
	}

	if (KEY_DOWN(VK_SPACE))
		jumpVelocity = JUMP_POWER;

	jumpVelocity -= GRAVITY * DELTA;

	pos.y -= jumpVelocity * DELTA;
}

void Plane::Render(HDC hdc)
{
	ImageRect::Render(hdc, { curFrame, 0 });
}
