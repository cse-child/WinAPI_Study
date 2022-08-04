#include "Framework.h"

Plane::Plane()
{
	pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	brush = CreateSolidBrush(RGB(100, 100, 200));
	collisionPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	collisionBrush = CreateSolidBrush(RGB(255, 255, 255));
	//bullet = new Bullet();
	bodyCircle = new Circle(position, BODY_CIRCLE_RADIUS);
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
	//PlaneCollision();
	//BulletCollision();
	//bullet->Update();
}

void Plane::Render(HDC hdc)
{
	bodyCircle->SetPenBrush(collisionPen, collisionBrush);
	bodyCircle->Render(hdc);

	DrawBody(hdc);
	//bullet->Render(hdc);
}

void Plane::DrawBody(HDC hdc)
{
	SelectObject(hdc, pen);
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
	bodyCircle->Pos() = position;
}

void Plane::ControlFire()
{
	delayCount++;

	if (delayCount < FIRE_DELAY_TIME) return;

	if (GetAsyncKeyState(VK_SPACE))
	{
		firePos = position;
		firePos.y -= TOP_SIZE;

		BulletManager::Get()->Fire(firePos);
		//bullet->Fire(firePos);
		delayCount = 0;
	}
}

void Plane::PlaneCollision()
{
	for (DropCircle* circle : DropManager::Get()->GetCircles())
	{
		if (!circle->Active()) return;

		float d = Distance(bodyCircle->Pos(), circle->Pos());
	
		if (d <= BODY_CIRCLE_RADIUS + circle->Radius())
		{
			GameManager::Get()->Stop();

			MessageBox(GameManager::Get()->GetHWND(),
				L"떨어지는 도형에 맞아 비행기가 폭발하였습니다!", L"Result", MB_OK);

			PostQuitMessage(0);
		}
	}
}


