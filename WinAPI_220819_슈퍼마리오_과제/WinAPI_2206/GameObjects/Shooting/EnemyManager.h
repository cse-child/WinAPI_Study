#pragma once

class EnemyManager : public Singleton<EnemyManager>
{
public:
    EnemyManager();
    ~EnemyManager();

    void Update();
    void Render(HDC hdc);

    void CreateEnemies(UINT poolingCount);

    Enemy* IsCollision(Rect * rect);

    void SetTarget(Rect* target);
private:
    void Spawn();

private:
    vector<Enemy *> enemies;

    float playTime = 0.0f;
    float spawnTime = 1.0f;
};