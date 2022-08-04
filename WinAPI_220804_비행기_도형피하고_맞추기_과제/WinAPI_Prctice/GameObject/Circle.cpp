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

	if (pen != nullptr && brush != nullptr)
	{
		SelectObject(hdc, pen);
		SelectObject(hdc, brush);
	}

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
	float distance = Distance(this->pos, pos);

	return distance <= radius;
}
