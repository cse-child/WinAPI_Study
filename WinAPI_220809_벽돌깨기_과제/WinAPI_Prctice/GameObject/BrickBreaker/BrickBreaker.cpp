#include "Framework.h"

BrickBreaker::BrickBreaker()
{
	pos = { CENTER_X, WIN_HEIGHT - CONTROL_BAR_HEIGHT };
	size = { CONTROL_BAR_WIDTH, CONTROL_BAR_HEIGHT };

	barBrush = CreateSolidBrush(GRAY);
	ballBrush = CreateSolidBrush(MAGENTA);

	ball = new Bullet(ballBrush);
	ball->Pos() = {CENTER_X, Top() - BALL_RADIUS};
	ball->Active() = true;
	
	collisionBall = new Rect(ball->Pos(), { BALL_RADIUS*2,BALL_RADIUS*2 });
}

BrickBreaker::~BrickBreaker()
{
	delete ball;
	delete collisionBall;

	DeleteObject(barBrush);
	DeleteObject(ballBrush);
}

void BrickBreaker::Update()
{
	Move();
	
	if (isBallMove)
	{
		ball->Pos().x = pos.x;
		BallMove();
	}

	Collision();

	ball->Update();

	collisionBall->Pos() = ball->Pos();
}

void BrickBreaker::Render(HDC hdc)
{
	SelectObject(hdc, barBrush);
	Rect::Render(hdc);

	//SelectObject(hdc, barBrush);
	//collisionBall->Render(hdc);

	SelectObject(hdc, ballBrush);
	ball->Render(hdc);
}

void BrickBreaker::Move()
{
	if (KEY_PRESS(VK_RIGHT))
	{
		pos.x += speed;
		if (Right() >= WIN_WIDTH)
			pos.x  = WIN_WIDTH - CONTROL_BAR_WIDTH / 2;
	}
	if (KEY_PRESS(VK_LEFT))
	{
		pos.x -= speed;
		if (Left() <= 0)
			pos.x = CONTROL_BAR_WIDTH/2;
	}
}

void BrickBreaker::BallMove()
{
	if (KEY_DOWN(VK_SPACE))
	{
		direction = (ball->Pos() - pos).Normalized();

		ball->Fire(ball->Pos(), direction);

		isBallMove = false;
	}
}

void BrickBreaker::Collision()
{
	Vector2 overlapSize;
	isCollision = IsCollision(collisionBall, overlapSize);

	if (isCollision)
	{
		direction = (ball->Pos() - pos).Normalized();
		ball->SetDirection(direction);

		if (overlapSize.x > overlapSize.y) // 상하 충돌
		{
			if (pos.y > collisionBall->Pos().y) // 상
				ball->Pos().y -= overlapSize.y;
			else // 하
				ball->Pos().y += overlapSize.y;
		}
		else // 좌우 충돌
		{
			if (pos.x > collisionBall->Pos().x) // 우
				ball->Pos().x -= overlapSize.x;
			else // 좌
				ball->Pos().x += overlapSize.x;
		}
	}
}
