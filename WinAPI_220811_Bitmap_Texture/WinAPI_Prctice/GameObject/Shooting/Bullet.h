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
	void Fire(Vector2 pos, Vector2 direction);

private:

	float speed = 10.0f;
	float angle = PI / 2; // 90µµ
	Vector2 direction;

	HBRUSH brush;
};