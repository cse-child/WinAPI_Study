#include "Framework.h"

SpawnCircle::SpawnCircle()
	:Circle({0,0},0)
{

}

SpawnCircle::SpawnCircle(POINT pos, UINT radius)
	:Circle(pos, radius)
{
}

SpawnCircle::~SpawnCircle()
{
}

void SpawnCircle::Update()
{
	if (!isActive) return;

	lifeTime++;

	if (lifeTime >= safeTime)
		isActive = false;
}

void SpawnCircle::Render(HDC hdc)
{
	if (!isActive) return;

	SelectObject(hdc, brush);
	Circle::Render(hdc);
}

void SpawnCircle::Spawn()
{
	isActive = true;

	safeTime = Random(MIN_LIFE_TIME, MAX_LIFE_TIME);
	lifeTime = 0;

	pos.x = Random(0, WIN_WIDTH);
	pos.y = Random(0, WIN_HEIGHT);

	radius = Random(MIN_RADIUS, MAX_RADIUS);
}
