#include "Framework.h"
#include "Enemy.h"

Enemy::Enemy()
{
	SetTexture(TEXTURE->Add(L"Textures/Enemy.bmp", 53, 42));

	isActive = false;

	hpBar = new HpBar({ pos.x, pos.y - size.y * 0.8f }, { 70, 15 }, 20);
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	if (!isActive) return;

	spawnTime = Random(3.0f, 10.0f);
	playTime += DELTA;

	if (playTime > spawnTime)
	{
		Fire();
		playTime = 0.0f;
	}

	Move();

	hpBar->Update();
	hpBar->Pos() = { pos.x, pos.y - size.y * 0.8f };
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

void Enemy::Fire()
{
	firePos.x = Left();
	firePos.y = pos.y;
	
	BulletManager::Get()->Fire("Enemy", firePos, Vector2(-1, 0));
}
