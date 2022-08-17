#include "Framework.h"

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
    for (Enemy * enemy : enemies)
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

    for (Enemy * enemy : enemies)
        enemy->Update();
}

void EnemyManager::Render(HDC hdc)
{
    for (Enemy * enemy : enemies)
        enemy->Render(hdc);
}

void EnemyManager::CreateEnemies(UINT poolingCount)
{
    enemies.resize(poolingCount);

    for (Enemy *& enemy : enemies)
    {
        enemy = new Enemy();
    }
}

Enemy* EnemyManager::IsCollision(Rect * rect)
{
    for (Enemy * enemy : enemies)
    {
        if (enemy->IsCollision(rect))
        {
            return enemy;
        }
    }

    return nullptr;
}

void EnemyManager::Spawn()
{
    for (Enemy * enemy : enemies)
    {
        if (!enemy->Active())
        {            
            enemy->Init();
            return;
        }
    }
}
