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
}

void DropCircle::InitCircle()
{
	isActive = true;

	radius = Random(MIN_RADIUS, MAX_RADIUS);

	pos.x = Random(radius, WIN_WIDTH - radius);
	pos.y = -radius;

	speed = Random(MIN_SPEED, MAX_SPEED);
}

void DropCircle::Move()
{
	pos.y += speed;

	if (pos.y + radius > WIN_HEIGHT)
	{
		isActive = false;
	}
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
