#pragma once

class Arrow
{
private:
	const float ARROW_SIZE = 30;
	const UINT BODY_RADIUS_LENGTH = 40;
public:
	Arrow();
	~Arrow();

	void Update();
	void Render(HDC hdc);

private:
	void CreateBodyLine();
	void Move();
	void AngleMove();

private:
	vector<Line*> bodyLine;
	Vector2 pos = { CENTER_X, CENTER_Y };

	Circle* bodyCollision;

	float angle = PI / 6;

	float speed = 10.0f;
};