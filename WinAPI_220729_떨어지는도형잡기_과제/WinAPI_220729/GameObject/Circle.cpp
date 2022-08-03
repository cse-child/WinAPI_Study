#include "Framework.h"

Circle::Circle(POINT pos, UINT radius)
    :radius(radius)
{
    this->pos = pos;
}

Circle::~Circle()
{
}

void Circle::Render(HDC hdc)
{
	if (!isActive) return;

    SelectObject(hdc, brush);
    Ellipse(hdc, pos.x - radius, pos.y - radius, pos.x + radius, pos.y + radius);
}

bool Circle::IsCollision(POINT pos)
{
    int distance = sqrt(pow(this->pos.x - pos.x, 2) + pow(this->pos.y - pos.y, 2));

    return distance<=radius;
}
