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

// 피타고라스 정리를 이용한 원 중앙과 점 사이의 거리 구하기
bool Circle::IsCollision(POINT pos)
{
	int x = pos.x - this->pos.x;
	int y = pos.y - this->pos.y;

	int distance = sqrt(x * x + y * y);

	return distance <= radius;
}
