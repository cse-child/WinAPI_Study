#pragma once

class Siva : public Rect
{
private:
	const float JUMP_POWER = 500.0f;
	const float GRAVITY = 980.0f;
public:
	Siva();
	~Siva();

	void Update();
	void Render(HDC hdc);
	
private:
	void Animation();
	void Move();
	void Jump();
private:
	HDC memDC;
	HBITMAP hbitmap;

	POINT imageSize;
	POINT imageFrame;
	POINT cutSize;
	POINT curFrame;

	float time = 0.0f;
	float speed = 200.0f;

	float jumpVelocity = 0.0f; // 점프속력
};