#pragma once

class Bullet
{
private:
	const UINT MAX_LIFE_TIME = 100;

public:
	Bullet();
	~Bullet();

	void Update();
	void Render(HDC hdc);

	void Shoot();

	bool& Active() { return isActive; }
	POINT& Pos() { return pos; }
	void SetBulletPos(POINT pos);

private:
	POINT pos = { (int)CENTER_X, (int)CENTER_Y };
	UINT radius;

	bool isActive = false;

	UINT lifeTime = 0;
	UINT safeTime = 0;
};