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

// ��Ÿ��� ������ �̿��� �� �߾Ӱ� �� ������ �Ÿ� ���ϱ�
bool Circle::IsCollision(Vector2 pos)
{
	float distance = Distance(this->pos, pos);

	return distance <= radius;
}
