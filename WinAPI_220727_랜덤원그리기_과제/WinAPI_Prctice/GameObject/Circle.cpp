#include "Framework.h"

Circle::Circle(POINT pos, int radius)
	:pos(pos), radius(radius)
{
	randomPen = CreatePen(PS_SOLID, 3, RGB((rand() % 256), (rand() % 256), (rand() % 256)));
	randomBrush = CreateSolidBrush(RGB((rand() % 256), (rand() % 256), (rand() % 256)));
}

Circle::~Circle()
{
}

void Circle::Render(HDC hdc)
{
	SelectObject(hdc, randomPen);
	SelectObject(hdc, randomBrush);

	Ellipse(hdc, pos.x - radius, pos.y - radius, 
		pos.x + radius, pos.y + radius);
}
