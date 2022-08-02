#pragma once

class Circle
{
public:
	Circle(POINT pos, UINT radius);
	~Circle();

	void Render(HDC hdc);

	bool IsCollision(POINT pos);

	POINT& Pos() { return pos; }

protected:
	POINT pos;
	UINT radius;
};