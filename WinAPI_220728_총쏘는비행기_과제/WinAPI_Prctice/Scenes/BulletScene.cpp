#include "Framework.h"
#include "BulletScene.h"

BulletScene::BulletScene()
{
	bullets.resize(MAX_BULLET_COUNT);

	for (UINT i = 0; i < MAX_BULLET_COUNT; i++)
	{
		bullets[i] = new Bullet();
	}
}

BulletScene::~BulletScene()
{
	for (Bullet* bullet : bullets)
		delete bullet;
}

void BulletScene::Shoot()
{
	for (Bullet* bullet : bullets)
	{
		if (!bullet->Active())
		{
			bullet->Shoot();
			return;
		}

	}
}

void BulletScene::Update()
{
	playTime++;

	if (playTime > spawnTime)
	{
		Shoot();
		playTime = 0;
	}

	for (Bullet* bullet : bullets)
		bullet->Update();
}

void BulletScene::Render(HDC hdc)
{
	for (Bullet* bullet : bullets)
		bullet->Render(hdc);
}
