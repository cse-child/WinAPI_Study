#include "Framework.h"

Circle::Circle()
{
}

Circle::Circle(Vector2 pos, float radius)
	:pos(pos), radius(radius)
{
}

Circle::~Circle()
{
}

void Circle::Render(HDC hdc)
{
	if (!isActive) return;
	Ellipse(hdc, 
	(int)(pos.x - radius), 
	 (int)(pos.y - radius), 
	(int)(pos.x + radius), 
	(int)(pos.y + radius)
	);
}

// 피타고라스 정리를 이용한 원 중앙과 점 사이의 거리 구하기
bool Circle::IsCollision(Vector2 pos)
{
	float x = pos.x - this->pos.x;
	float y = pos.y - this->pos.y;

	float distance = sqrtf(x * x + y * y);

	return distance <= radius;
}
