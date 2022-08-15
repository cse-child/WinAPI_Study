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

private:
	float jumpVelocity = 0.0f; // �����ӷ�

	int curFrame = 0;
	float time = 0;
};