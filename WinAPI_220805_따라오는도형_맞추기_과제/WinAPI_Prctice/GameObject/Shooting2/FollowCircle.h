#pragma once

class FollowCircle : public Circle
{
private:
	const float MIN_SPEED = 3.0f;
	const float MAX_SPEED = 7.0f;
	const float MIN_RADIUS = 15.0f;
	const float MAX_RADIUS = 50.0f;

	enum RandomPos
	{
		UP,
		RIGHT,
		DOWN,
		LEFT,
		MAX
	};

public:
	FollowCircle();
	~FollowCircle();

	void Update();
	void Render(HDC hdc);

	void SetBrush(HBRUSH brush) { this->brush = brush; }

	void InitCircle();

private:
	void Move();

private:
	HBRUSH brush = nullptr;
	float speed = 0.0f;

};