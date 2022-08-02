#pragma once

class Rect
{
public:
	Rect(POINT startPos, POINT endPos);
	~Rect();

	void Render(HDC hdc);

	POINT& StartPos() { return startPos; }
	POINT& EndPos() { return endPos; }

	void SetBrush(HBRUSH brush) { this->brush = brush; }

private:
	POINT startPos;
	POINT endPos;

	HBRUSH brush;
};