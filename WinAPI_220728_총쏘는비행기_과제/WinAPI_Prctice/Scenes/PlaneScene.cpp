#include "Framework.h"
#include "PlaneScene.h"

PlaneScene::PlaneScene()
{
	bodyRect.resize(3);
	CreateBody();
}

PlaneScene::~PlaneScene()
{
	for (Rect* rect : bodyRect)
		delete rect;
}

void PlaneScene::Update()
{
	Move();
}

void PlaneScene::Render(HDC hdc)
{
	for (Rect* rect : bodyRect)
	{
		rect->SetBrush(brush);
		rect->Render(hdc);
	}
}

void PlaneScene::Move()
{
		if (GetAsyncKeyState(VK_RIGHT))
		{
			for (Rect* rect : bodyRect)
			{
				rect->StartPos().x += 10;
				rect->EndPos().x += 10;
			}
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			for (Rect* rect : bodyRect)
			{
				rect->StartPos().x -= 10;
				rect->EndPos().x -= 10;
			}
		}
		if (GetAsyncKeyState(VK_UP))
		{
			for (Rect* rect : bodyRect)
			{
				rect->StartPos().y -= 10;
				rect->EndPos().y -= 10;
			}
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			for (Rect* rect : bodyRect)
			{
				rect->StartPos().y += 10;
				rect->EndPos().y += 10;
			}
		}
}

void PlaneScene::CreateBody()
{
	POINT startPos = { CENTER_X - 25, WIN_HEIGHT - 150 };
	POINT endPos = { CENTER_X + 25, WIN_HEIGHT - 20 };
	bodyRect[0] = new Rect(startPos, endPos);

	startPos = { startPos.x - 35, startPos.y + 40 };
	endPos = { startPos.x + 35, endPos.y - 40 };
	bodyRect[1] = new Rect(startPos, endPos);

	startPos = { startPos.x + 85, startPos.y };
	endPos = { startPos.x + 35, endPos.y};
	bodyRect[2] = new Rect(startPos, endPos);

	brush = CreateSolidBrush(RGB(200, 200, 200));
}
