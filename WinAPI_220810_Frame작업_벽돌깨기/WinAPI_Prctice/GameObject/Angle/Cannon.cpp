#include "Framework.h"
#include "Cannon.h"

Cannon::Cannon()
{
	body = new Circle({ CENTER_X, CENTER_Y }, 100);

	barrel = new Line(body->Pos(), Vector2());

	BulletManager::Get()->CreateBullets(100);
}

Cannon::~Cannon()
{
	delete body;
	delete barrel;

	BulletManager::Get()->Delete();
}

void Cannon::Update()
{

	/* 마우스 위치로 각도 구하기 (역삼각비) */
	float x = mousePos.x - body->Pos().x;
	float y = mousePos.y - body->Pos().y;
	//angle = atanf(-y / x);
	angle = atan2f(-y, x);

	/* 삼각비 이용한 좌표 구하기*/
	x = cosf(angle) * barrelLength + body->Pos().x;
	// 게임은 수학좌표와 y가 반대
	y = -sinf(angle) * barrelLength + body->Pos().y;

	barrel->End() = { x, y };

	if (GetAsyncKeyState(VK_UP))
		angle += 0.1f;
	
	if (GetAsyncKeyState(VK_DOWN))
		angle -= 0.1f;

	if (KEY_DOWN(VK_SPACE))
	{
		BulletManager::Get()->Fire(barrel->End(), 
			(mousePos - body->Pos()).Normalized());
	}

	BulletManager::Get()->Update();
}

void Cannon::Render(HDC hdc)
{
	body->Render(hdc);
	barrel->Render(hdc);

	BulletManager::Get()->Render(hdc);

	wstring radian = L"RadianAngle : " + to_wstring(angle) + L"Radian";
	TextOut(hdc, 0, 0, radian.c_str(), radian.length());

	wstring degree = L"DegreeAngle : " + to_wstring(angle * 180.0f / PI) + L"Degree";
	TextOut(hdc, 0, 20, degree.c_str(), degree.length());
}
