#pragma once

class AvoidPlayer : public Circle
{
public:
	AvoidPlayer();
	~AvoidPlayer();

	void Update();
	void Render(HDC hdc);

private:
	void DrawBody(HDC hdc);
	
	void Move();

private:
	float speed = 5.0f;
	float angle = 0.0f;

	HPEN pen = nullptr;
	HPEN defaultPen = nullptr;

	vector<Line*> bodyLines;

	Vector2 direction;
	Vector2 frontPos;
};