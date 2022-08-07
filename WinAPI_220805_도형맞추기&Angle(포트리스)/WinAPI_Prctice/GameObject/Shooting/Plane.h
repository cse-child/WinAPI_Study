#pragma once

class Plane
{
private:
	const int LEFT_SIZE = 100;
	const int RIGHT_SIZE = 100;
	const int TOP_SIZE = 110;
	const int BOTTOM_SIZE = 100;

	const int FIRE_DELAY_TIME = 20;
public:
	Plane();
	~Plane();

	void Update(); // �̵�ó��, �ѽ��ó��
	void Render(HDC hdc);

private:
	void DrawBody(HDC hdc);
	void DrawHpBar(HDC hdc);

	void ControlMove();
	void ControlFire();
	void Collision();

	void Init();

private:
	int speed = 5;
	int delayCount = FIRE_DELAY_TIME;
	int maxHp = 100;
	int curHp = 100;
	
	Vector2 position = {(int)CENTER_X, (int)CENTER_Y};

	HBRUSH brush;
	HBRUSH hpBackBrush;
	HBRUSH hpFrontBrush;

	Circle* collisionCircle;
};