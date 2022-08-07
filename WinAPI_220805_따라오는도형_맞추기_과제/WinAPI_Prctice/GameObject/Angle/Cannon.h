#pragma once

class Cannon
{
private:
	const UINT BODY_RADIUS_LENGTH = 50;

public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	Vector2 GetPlayerPos() { return body->Pos(); }

private:
	void Move();
	void BarrelMove();
	void Collision();

private:
	Circle* body;
	Line* barrel; // Æ÷½Å

	float angle = PI / 6;
	float barrelLength = 100;

	float speed = 10.0f;

	float playTime = 0;

	HBRUSH brush;
};