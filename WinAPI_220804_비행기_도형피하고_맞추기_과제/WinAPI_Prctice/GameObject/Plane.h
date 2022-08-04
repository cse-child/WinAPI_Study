#pragma once

class Plane
{
private:
	const int LEFT_SIZE = 100;
	const int RIGHT_SIZE = 100;
	const int TOP_SIZE = 110;
	const int BOTTOM_SIZE = 100;

	const int FIRE_DELAY_TIME = 20;

	const int BODY_CIRCLE_RADIUS = 110;
public:
	Plane();
	~Plane();

	void Update(); // �̵�ó��, �ѽ��ó��
	void Render(HDC hdc);

	void PlaneCollision();
	//void BulletCollision();

private:
	void DrawBody(HDC hdc);
	void ControlMove();
	void ControlFire();
	
private:
	int speed = 5;
	int delayCount = FIRE_DELAY_TIME;
	
	POINT position = {(int)CENTER_X, (int)WIN_HEIGHT-BOTTOM_SIZE};

	HPEN pen;
	HBRUSH brush;
	HPEN collisionPen;
	HBRUSH collisionBrush;

	Circle* bodyCircle;

	Vector2 firePos;
};