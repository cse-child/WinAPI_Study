#include "Framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	rect = new Rect({ CENTER_X, CENTER_Y }, { 100, 200 });
	rect2 = new Rect({ CENTER_X, CENTER_Y }, { 200, 100 });
	circle = new Circle({ CENTER_X, CENTER_Y }, 100);

	redBrush = CreateSolidBrush(RED);
	blueBrush = CreateSolidBrush(BLUE);
}

CollisionScene::~CollisionScene()
{
	delete rect;
	delete rect2;
	delete circle;

	DeleteObject(redBrush);
	DeleteObject(blueBrush);
}

void CollisionScene::Update()
{
	//rect->Pos() = mousePos;
	circle->Pos() = mousePos;

	isCollision = rect->IsCollision(circle);

	Vector2 overlapSize;

	//isCollision = rect->IsCollision(rect2, overlapSize);

	if (isCollision)
	{
		// 겹치는 사각형의 가로가 더 크다 = 상하 충돌
		if (overlapSize.x > overlapSize.y)
		{
			if (rect->Pos().y > rect2->Pos().y)
				rect2->Pos().y -= overlapSize.y;
			else
				rect2->Pos().y += overlapSize.y;
		}
		else // 좌우 충돌
		{
			// 첫번째 사각형이 더 오른쪽에 있다 = 오른쪽으로 밀어냄
			if (rect->Pos().x > rect2->Pos().x)
				rect2->Pos().x -= overlapSize.x;
			else
				rect2->Pos().x += overlapSize.x;
		}
	}
}

void CollisionScene::Render(HDC hdc)
{
	if (isCollision)
		SelectObject(hdc, redBrush);
	else
		SelectObject(hdc, blueBrush);

	rect->Render(hdc);
	rect2->Render(hdc);
	circle->Render(hdc);
}
