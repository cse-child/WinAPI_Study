#include "Framework.h"
#include "Cannon.h"

Cannon::Cannon()
{
	body = new Circle({ CENTER_X, CENTER_Y }, BODY_RADIUS_LENGTH);

	barrel = new Line(body->Pos(), Vector2());

	brush = CreateSolidBrush(RGB(100, 100, 100));

	BulletManager::Get()->CreateBullets(50);
}

Cannon::~Cannon()
{
	delete body;
	delete barrel;
	DeleteObject(brush);

	BulletManager::Get()->Delete();
}

void Cannon::Update()
{
	playTime += 0.02f;

	Move();
	BarrelMove();
	Collision();

	if (GetAsyncKeyState(VK_LBUTTON))
		BulletManager::Get()->Fire(barrel->End(), angle);

	BulletManager::Get()->Update();
}

void Cannon::Render(HDC hdc)
{
	SelectObject(hdc, brush);
	body->Render(hdc);
	barrel->Render(hdc);

	BulletManager::Get()->Render(hdc);

	wstring playTimeStr = L"Play Time : " + to_wstring(playTime) + L" s";
	TextOut(hdc, 0, 20, playTimeStr.c_str(), playTimeStr.length());
}

void Cannon::Move()
{
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (body->Pos().x >= WIN_WIDTH - BODY_RADIUS_LENGTH)
			return;

		body->Pos().x += speed;
		barrel->Start().x += speed;
		barrel->End().x += speed;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (body->Pos().x <= BODY_RADIUS_LENGTH)
			return;

		body->Pos().x -= speed;
		barrel->Start().x -= speed;
		barrel->End().x -= speed;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		if (body->Pos().y <= BODY_RADIUS_LENGTH)
			return;

		body->Pos().y -= speed;
		barrel->Start().y -= speed;
		barrel->End().y -= speed;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		if (body->Pos().y >= WIN_HEIGHT - BODY_RADIUS_LENGTH)
			return;

		body->Pos().y += speed;
		barrel->Start().y += speed;
		barrel->End().y += speed;
	}
}

void Cannon::BarrelMove()
{
	/* 마우스 위치로 각도 구하기 (역삼각비) */
	float x = mousePos.x - body->Pos().x;
	float y = mousePos.y - body->Pos().y;
	angle = atan2f(-y, x);

	/* 삼각비 이용한 좌표 구하기*/
	x = cosf(angle) * barrelLength + body->Pos().x;
	// 게임은 수학좌표와 y가 반대
	y = -sinf(angle) * barrelLength + body->Pos().y;

	barrel->End() = { x, y };
}

void Cannon::Collision()
{
	if (FollowManager::Get()->IsCollision(body))
	{
		GameManager::Get()->Stop();
		MessageBox(GameManager::Get()->GetHWND(),
			L"GameOver", L"GameOver", MB_OK);
		PostQuitMessage(0);
	}
}
