#pragma once

class Circle
{
public:
	Circle(POINT pos, int radius);
	~Circle();

	void Render(HDC hdc);

	POINT& Pos() { return pos; }

private:
	POINT pos;
	UINT radius;
	HPEN randomPen;
	HBRUSH randomBrush;
};