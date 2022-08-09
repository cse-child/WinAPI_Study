#pragma once

class BrickBreaker : public Rect
{
private:
	const float CONTROL_BAR_WIDTH = 300.0f;
	const float CONTROL_BAR_HEIGHT = 50.0f;

	const float BALL_RADIUS = 20.0f;

public:
	BrickBreaker();
	~BrickBreaker();

	void Update();
	void Render(HDC hdc);

private:
	void Move();
	void BallMove();
	void Collision();

private:
	Bullet* ball;
	Rect* collisionBall;

	float speed = 10.0f;
	bool isBallMove = true;
	bool isCollision = false;

	Vector2 direction;

	HBRUSH barBrush;
	HBRUSH ballBrush;


};