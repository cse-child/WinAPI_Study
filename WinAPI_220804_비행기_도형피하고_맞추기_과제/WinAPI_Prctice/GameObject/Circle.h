#pragma once

class Circle
{
public:
	Circle();
	Circle(Vector2 pos, float radius);
	~Circle();

	void Render(HDC hdc);

	bool IsCollision(Vector2 pos);

	Vector2& Pos() { return pos; }
	bool& Active() { return isActive; }
	float Radius() { return radius; }

	void SetPenBrush(HPEN pen, HBRUSH brush) { this->pen = pen; this->brush = brush; }

protected:
	bool isActive = true;

	Vector2 pos;
	float radius = 0.0f;

	HPEN pen = nullptr;
	HBRUSH brush = nullptr;
};