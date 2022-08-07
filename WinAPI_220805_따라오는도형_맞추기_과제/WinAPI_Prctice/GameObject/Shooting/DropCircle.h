#pragma once

class DropCircle : public Circle
{
private:
	const float MIN_SPEED = 5.0f;
	const float MAX_SPEED = 10.0f;

	const float MIN_RADIUS = 30.0f;
	const float MAX_RADIUS = 60.0f;

public:
	DropCircle();
	~DropCircle();

	void Update();
	void Render(HDC hdc);

	void InitCircle();

	void SetBrush(HBRUSH brush) { this->brush = brush; }

private:
	void Move();
	void Collision();

private:
	float speed = 0.0f;

	HBRUSH brush = nullptr;
};