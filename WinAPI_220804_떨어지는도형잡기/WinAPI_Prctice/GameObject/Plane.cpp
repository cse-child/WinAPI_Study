#include "Framework.h"

Plane::Plane()
{
	brush = CreateSolidBrush(RGB(100, 100, 200));

	//bullet = new Bullet();
}

Plane::~Plane()
{
	DeleteObject(brush);
	//delete bullet;
}

void Plane::Update()
{
	ControlMove();
	ControlFire();
	//bullet->Update();
}

void Plane::Render(HDC hdc)
{
	DrawBody(hdc);
	//bullet->Render(hdc);
}

void Plane::DrawBody(HDC hdc)
{
	SelectObject(hdc, brush);
	
	// Body
	Rectangle(hdc, position.x - 30, position.y - 50,
		position.x + 30, position.y + 50);

	// Wing
	Ellipse(hdc, position.x - 100, position.y - 50,
		position.x + 100, position.y);

	// Head
	Ellipse(hdc, position.x - 30, position.y - 110,
		position.x + 30, position.y-50);

	// Left Leg
	Ellipse(hdc, position.x - 30, position.y +50,
		position.x, position.y+100);

	// Right Leg
	Ellipse(hdc, position.x, position.y + 50,
		position.x+30, position.y + 100);
}

void Plane::ControlMove()
{
	if (GetAsyncKeyState(VK_UP))
	{
		position.y -= speed;

		if (position.y < TOP_SIZE)
			position.y = TOP_SIZE;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		position.y += speed;

		if (position.y > WIN_HEIGHT-BOTTOM_SIZE)
			position.y = WIN_HEIGHT-BOTTOM_SIZE;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		position.x += speed;

		if (position.x > WIN_WIDTH - RIGHT_SIZE)
			position.x = WIN_WIDTH - RIGHT_SIZE;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		position.x -= speed;

		if (position.x < LEFT_SIZE)
			position.x = LEFT_SIZE;

	}
}

void Plane::ControlFire()
{
	delayCount++;

	if (delayCount < FIRE_DELAY_TIME) return;

	if (GetAsyncKeyState(VK_SPACE))
	{
		POINT firePos = position;
		firePos.y -= TOP_SIZE;

		BulletManager::Get()->Fire(firePos);
		//bullet->Fire(firePos);

		delayCount = 0;
	}
}
