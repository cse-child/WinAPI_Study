#include "Framework.h"

Circle::Circle(POINT pos, UINT radius)
	:pos(pos), radius(radius)
{
}

Circle::~Circle()
{
}

void Circle::Render(HDC hdc)
{
	Ellipse(hdc, pos.x - radius, pos.y - radius, 
		pos.x + radius, pos.y + radius);
}
