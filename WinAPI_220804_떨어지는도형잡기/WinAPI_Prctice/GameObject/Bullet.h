#pragma once

class Bullet : public Circle
{
public:
	Bullet(HBRUSH brush);
	~Bullet();

	void Update();
	void Render(HDC hdc);

	void Fire(Vector2 pos);

	bool IsActive() { return isActive; }

private:
	bool isActive = false;

	int speed = 5;

	HBRUSH brush;
};