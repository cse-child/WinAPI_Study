#include "Framework.h"

Arrow::Arrow()
{
	bodyLine.resize(5);
	CreateBodyLine();
	bodyCollision = new Circle(pos, BODY_RADIUS_LENGTH);
}

Arrow::~Arrow()
{
	for (Line* line : bodyLine)
		delete line;
}

void Arrow::Update()
{
	Move();
	AngleMove();
}

void Arrow::Render(HDC hdc)
{
	SelectObject(hdc, CreateSolidBrush(RGB(255,255,255)));
	bodyCollision->Render(hdc);
	for (Line* line : bodyLine)
		line->Render(hdc);
	
}

void Arrow::CreateBodyLine()
{
	bodyLine[0] = new Line({ pos.x, pos.y }, { pos.x - ARROW_SIZE, pos.y });
	bodyLine[1] = new Line({ pos.x - ARROW_SIZE, pos.y }, { pos.x + ARROW_SIZE, pos.y - ARROW_SIZE });
	bodyLine[2] = new Line({ pos.x - ARROW_SIZE, pos.y }, { pos.x + ARROW_SIZE, pos.y + ARROW_SIZE });
	bodyLine[3] = new Line({ pos.x, pos.y }, { pos.x + ARROW_SIZE, pos.y - ARROW_SIZE });
	bodyLine[4] = new Line({ pos.x, pos.y }, { pos.x + ARROW_SIZE, pos.y + ARROW_SIZE });
}

void Arrow::Move()
{
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (bodyCollision->Pos().x >= WIN_WIDTH - BODY_RADIUS_LENGTH)
			return;

		for (Line* line : bodyLine)
		{
			line->Start().x += speed;
			line->End().x += speed;
		}
		bodyCollision->Pos().x += speed;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (bodyCollision->Pos().x <= BODY_RADIUS_LENGTH)
			return;

		for (Line* line : bodyLine)
		{
			line->Start().x -= speed;
			line->End().x -= speed;
		}
		bodyCollision->Pos().x -= speed;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		if (bodyCollision->Pos().y <= BODY_RADIUS_LENGTH)
			return;

		for (Line* line : bodyLine)
		{
			line->Start().y -= speed;
			line->End().y -= speed;
		}
		bodyCollision->Pos().y -= speed;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		if (bodyCollision->Pos().y >= WIN_HEIGHT - BODY_RADIUS_LENGTH)
			return;

		for (Line* line : bodyLine)
		{
			line->Start().y += speed;
			line->End().y += speed;
		}
		bodyCollision->Pos().y += speed;
	}
}

void Arrow::AngleMove()
{
	/* ���콺 ��ġ�� ���� ���ϱ� (���ﰢ��) */
	float x = mousePos.x - bodyCollision->Pos().x;
	float y = mousePos.y - bodyCollision->Pos().y;
	angle = atan2f(-y, x);

	/* �ﰢ�� �̿��� ��ǥ ���ϱ�*/
	x = cosf(angle) * ARROW_SIZE + bodyCollision->Pos().x;
	// ������ ������ǥ�� y�� �ݴ�
	y = -sinf(angle) * ARROW_SIZE + bodyCollision->Pos().y;

	bodyLine[0]->End() = {x, y};
	bodyLine[1]->Start() = {x, y};
	bodyLine[2]->Start() = {x, y};

	//bodyLine[1]->Start().x += x;
	//bodyLine[1]->Start().y += y;
	//bodyLine[1]->End().x += x;
	//bodyLine[1]->End().y -= y;
}
