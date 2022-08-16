#include "Framework.h"
#include "Enemy.h"

Enemy::Enemy()
{
	SetTexture(TEXTURE->Add(L"Textures/Enemy.bmp", 53, 42));

	isActive = false;
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	if (!isActive) return;

	Move();
}

void Enemy::Init()
{
	isActive = true;

	pos.x = WIN_WIDTH + Half().x;
	pos.y = Random(Half().y, WIN_HEIGHT - Half().y);
}

void Enemy::Move()
{
	pos.x -= speed * DELTA;

	if (Right() < 0)
		isActive = false;
}
