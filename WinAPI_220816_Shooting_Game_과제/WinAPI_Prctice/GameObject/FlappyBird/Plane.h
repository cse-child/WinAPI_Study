#pragma once

class Plane : public ImageRect
{
private:
	const float JUMP_POWER = 500.0f;
	const float GRAVITY = 980.0f;

public:
	Plane();
	~Plane();

	void Update();
	void Render(HDC hdc);

	HpBar* GetHpBar() { return hpBar; }

private:
	void Animation();
	void Jump();
	void Move();
	void Fire();

private:
	float jumpVelocity = 0.0f; // ?????ӷ?
	float speed = 500.0f;

	int curFrame = 0;
	float time = 0;

	Vector2 firePos;
	HpBar* hpBar;
};