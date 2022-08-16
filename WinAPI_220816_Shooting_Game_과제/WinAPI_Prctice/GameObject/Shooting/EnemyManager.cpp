#include "Framework.h"

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
	for (Enemy* enemy : enemies)
		delete enemy;
}

void EnemyManager::Update()
{
	playTime += DELTA;

	if (playTime > spawnTime)
	{
		Spawn();
		playTime = 0.0f;
	}
	for (Enemy* enemy : enemies)
		enemy->Update();
}

void EnemyManager::Render(HDC hdc)
{
	for (Enemy* enemy : enemies)
	{
		enemy->Render(hdc);
		enemy->GetHpBar()->Render(hdc);
	}
}

void EnemyManager::CreateEnemies(UINT poolingCount)
{
	enemies.resize(poolingCount);

	for (Enemy*& enemy : enemies)
	{
		enemy = new Enemy();
	}
}

bool EnemyManager::IsCollision(Rect* rect)
{
	for (Enemy* enemy : enemies)
	{
		if (enemy->IsCollision(rect))
		{
			enemy->GetHpBar()->DecreaseHP(10);
			
			if (enemy->GetHpBar()->GetHP() <= 0)
			{
				enemy->Active() = false;
			}
			return true;
			
		}
	}
	return false;
}


void EnemyManager::Spawn()
{
	for (Enemy* enemy : enemies)
	{
		if (!enemy->Active())
		{
			enemy->Init();
			return;
		}
	}
}
