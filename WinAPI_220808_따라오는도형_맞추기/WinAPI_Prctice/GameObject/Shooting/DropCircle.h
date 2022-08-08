#pragma once

class DropCircle : public Circle
{
private:
	const float MIN_SPEED = 3.0f;
	const float MAX_SPEED = 5.0f;

	const float MIN_RADIUS = 30.0f;
	const float MAX_RADIUS = 60.0f;

public:
	DropCircle();
	~DropCircle();

	void Update();
	void Render(HDC hdc);

	void InitCircle();

	void SetBrush(HBRUSH brush) { this->brush = brush; }
	void SetTarget(Circle* target) { this->target = target; }

private:
	void Move();
	void Collision();

private:
	float speed = 0.0f;
	float rotSpeed = 0.01f;
	float angle = 0.0f;

	Vector2 direction;

	HBRUSH brush = nullptr;

	Circle* target;
};