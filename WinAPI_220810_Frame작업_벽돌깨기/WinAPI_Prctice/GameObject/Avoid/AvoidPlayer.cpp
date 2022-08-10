#include "Framework.h"

AvoidPlayer::AvoidPlayer()
{
	pen = CreatePen(PS_SOLID, 3, BLUE);
	radius = 30;

	pos = { CENTER_X, CENTER_Y };

	bodyLines.resize(5);
	for (Line*& line : bodyLines)
		line = new Line();

	BulletManager::Get()->CreateBullets(50);
}

AvoidPlayer::~AvoidPlayer()
{
	DeleteObject(pen);

	for (Line* line : bodyLines)
		delete line;

	BulletManager::Delete();
}

void AvoidPlayer::Update()
{
	//float x = mousePos.x - pos.x;
	//float y = mousePos.y - pos.y;

	// 플레이어 위치에서 마우스 위치로 향하는 벡터
	// (연산자 오버로딩)
	// 벡터 특성에 의해 A-B는 B->A 결과가 나온다.
	// 벡터 종류: 단위 벡터 - 방향 벡터
	direction = mousePos - pos;

	//angle = atan2f(-direction.y, direction.x);
	angle = direction.Angle();

	Move();

	frontPos = pos;
	if (GetAsyncKeyState(VK_LBUTTON))
		BulletManager::Get()->Fire(frontPos, direction.Normalized());

	BulletManager::Get()->Update();
}

void AvoidPlayer::Render(HDC hdc)
{
	Circle::Render(hdc);
	
	DrawBody(hdc);

	BulletManager::Get()->Render(hdc);
}

void AvoidPlayer::DrawBody(HDC hdc)
{
	Vector2 frontPos = pos + direction.Normalized() * radius;

	frontPos.x = pos.x + cosf(angle) * radius;
	frontPos.y = pos.y - sinf(angle) * radius;

	float tempAngle = angle + PI * 2.0f / 3.0f;

	Vector2 rightPos;
	rightPos.x = pos.x + cosf(tempAngle) * radius;
	rightPos.y = pos.y - sinf(tempAngle) * radius;

	tempAngle = angle - PI * 2.0f / 3.0f;

	Vector2 leftPos;
	leftPos.x = pos.x + cosf(tempAngle) * radius;
	leftPos.y = pos.y - sinf(tempAngle) * radius;
	
	//ForwardLine
	bodyLines[0]->Start() = pos;
	bodyLines[0]->End() = frontPos;

	// RightWing
	bodyLines[1]->Start() = frontPos;
	bodyLines[1]->End() = rightPos;
	bodyLines[2]->Start() = pos;
	bodyLines[2]->End() = rightPos;

	// LeftWing
	bodyLines[3]->Start() = frontPos;
	bodyLines[3]->End() = leftPos;
	bodyLines[4]->Start() = pos;
	bodyLines[4]->End() = leftPos;

	// 원래 쓰던 펜을 저장해놓음
	defaultPen = (HPEN)SelectObject(hdc, pen);

	for (Line* line : bodyLines)
		line->Render(hdc);

	SelectObject(hdc, defaultPen);
}

void AvoidPlayer::Move()
{
	if (GetAsyncKeyState('D'))
	{
		pos.x += speed;
	}
	if (GetAsyncKeyState('A'))
	{
		pos.x -= speed;
	}
	if (GetAsyncKeyState('W'))
	{
		pos.y -= speed;
	}
	if (GetAsyncKeyState('S'))
	{
		pos.y += speed;
	}
}
