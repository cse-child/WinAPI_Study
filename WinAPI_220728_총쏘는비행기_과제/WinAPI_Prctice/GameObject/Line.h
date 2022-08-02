#pragma once


class Line
{
public:
	Line(POINT startPos, POINT endPos);
	~Line();

	void Render(HDC hdc);

private:
	POINT startPos;
	POINT endPos;
};