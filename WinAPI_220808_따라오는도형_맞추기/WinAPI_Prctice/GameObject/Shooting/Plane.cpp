#include "Framework.h"

Plane::Plane()
{
	brush = CreateSolidBrush(RGB(100, 100, 200));
	hpBackBrush = CreateSolidBrush(RGB(255, 0, 0));
	hpFrontBrush = CreateSolidBrush(RGB(255, 255, 0));

	collisionCircle = new Circle(position, TOP_SIZE);

	BulletManager::Get()->CreateBullets(50);
}

Plane::~Plane()
{
	DeleteObject(brush);
	DeleteObject(hpBackBrush);
	DeleteObject(hpFrontBrush);
	
	delete collisionCircle;

	BulletManager::Get()->Delete();
}

void Plane::Update()
{
	ControlMove();
	ControlFire();
	Collision();

	collisionCircle->Pos() = position;
	
	BulletManager::Get()->Update();
}

void Plane::Render(HDC hdc)
{
	//collisionCircle->Render(hdc);
	DrawBody(hdc);
	DrawHpBar(hdc);

	BulletManager::Get()->Render(hdc);
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

void Plane::DrawHpBar(HDC hdc)
{
	SelectObject(hdc, hpBackBrush);
	Rectangle(hdc, 30, 30, 30 + maxHp * 2, 70);
	
	SelectObject(hdc, hpFrontBrush);
	Rectangle(hdc, 30, 30, 30 + curHp * 2, 70);
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
		Vector2 firePos = position;
		firePos.y -= TOP_SIZE;

		BulletManager::Get()->Fire(firePos);

		delayCount = 0;
	}
}

void Plane::Collision()
{
	if (DropManager::Get()->IsCollision(collisionCircle))
	{
		curHp -= 5;
	}

	if (curHp <= 0)
	{
		GameManager::Get()->Stop();
		MessageBox(GameManager::Get()->GetHWND(),
			L"GameOver", L"GameOver", MB_OK);
		Init();
		DropManager::Get()->Init();
		GameManager::Get()->Play();
	}
}

void Plane::Init()
{
	curHp = maxHp;
	position = { CENTER_X, CENTER_Y };
}
