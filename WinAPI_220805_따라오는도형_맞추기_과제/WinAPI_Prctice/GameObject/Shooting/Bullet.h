#pragma once

class Bullet : public Circle
{
public:
	Bullet(HBRUSH brush);
	~Bullet();

	void Update();
	void Render(HDC hdc);

	void Fire(Vector2 pos);
	void Fire(Vector2 pos, float angle);

private:

	float speed = 10.0f;

	float angle = PI / 2; // 90µµ

	HBRUSH brush;
};