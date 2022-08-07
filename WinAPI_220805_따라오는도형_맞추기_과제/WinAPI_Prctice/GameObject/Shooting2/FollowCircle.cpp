#include "Framework.h"
#include "FollowCircle.h"

FollowCircle::FollowCircle()
{
	isActive = false;
}

FollowCircle::~FollowCircle()
{
}

void FollowCircle::Update()
{
	if (!isActive) return;

	Move();
}

void FollowCircle::Render(HDC hdc)
{
	SelectObject(hdc, brush);
	Circle::Render(hdc);
}

void FollowCircle::InitCircle()
{
	isActive = true;
	speed = Random(MIN_SPEED, MAX_SPEED);
	radius = Random(MIN_RADIUS, MAX_RADIUS);

	int randPos = Random(0, MAX);

	switch (randPos)
	{
	case FollowCircle::UP:
		pos.x = Random(-radius, WIN_WIDTH + radius);
		pos.y = -radius;
		break;
	case FollowCircle::RIGHT:
		pos.x = WIN_WIDTH + radius;
		pos.y = Random(-radius, WIN_HEIGHT + radius);
		break;
	case FollowCircle::DOWN:
		pos.x = Random(-radius, WIN_WIDTH + radius);
		pos.y = WIN_HEIGHT + radius;
		break;
	case FollowCircle::LEFT:
		pos.x = -radius;
		pos.y = Random(-radius, WIN_HEIGHT + radius);
		break;
	}
}

void FollowCircle::Move()
{
	Vector2 playerPos = FollowManager::Get()->GetPlayerPos();

	if (playerPos.x - pos.x < 0)
		pos.x -= speed;
	else if (playerPos.x - pos.x > 0)
		pos.x += speed;

	if (playerPos.y - pos.y < 0)
		pos.y -= speed;
	else if (playerPos.y - pos.y > 0)
		pos.y += speed;
}
