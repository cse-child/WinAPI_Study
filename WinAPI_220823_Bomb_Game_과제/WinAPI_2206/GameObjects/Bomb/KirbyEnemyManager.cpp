#include "Framework.h"

KirbyEnemyManager::KirbyEnemyManager()
{
}

KirbyEnemyManager::~KirbyEnemyManager()
{
	for (KirbyEnemy* enemy : enemies)
		delete enemy;
	enemies.clear();
}

void KirbyEnemyManager::Update()
{
	playTime += DELTA;

	if (playTime > spawnTime)
	{
		playTime = 0.0f;
		Drop();
	}

	for (KirbyEnemy* enemy : enemies)
		enemy->Update();
}

void KirbyEnemyManager::Render(HDC hdc)
{
	for (KirbyEnemy* enemy : enemies)
		enemy->Render(hdc);
}

void KirbyEnemyManager::Drop()
{
	for (KirbyEnemy* enemy : enemies)
	{
		if (!enemy->Active())
		{
			enemy->Drop();
			return;
		}
	}
}

void KirbyEnemyManager::CreateEnemies(UINT poolingCount)
{
	enemies.resize(poolingCount);

	for (KirbyEnemy*& enemy : enemies)
	{
		enemy = new KirbyEnemy();
	}
}

void KirbyEnemyManager::SetLandTexture(Texture* texture)
{
	for (KirbyEnemy* enemy : enemies)
		enemy->SetLandTexture(texture);
}

void KirbyEnemyManager::SetPlayerPos(Vector2 pos)
{
	for (KirbyEnemy* enemy : enemies)
		enemy->SetPlayerPos(pos);
}

void KirbyEnemyManager::CollisionExplodeCircle(Circle* circle)
{
	for (KirbyEnemy* enemy : enemies)
	{
		if (enemy->CollisionExplodeCircle(circle))
		{
			enemy->Active() = false;
			return;
		}
	}
}