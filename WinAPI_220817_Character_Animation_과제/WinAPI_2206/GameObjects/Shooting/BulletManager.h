#pragma once

class BulletManager : public Singleton<BulletManager>
{
public:
    BulletManager();
    ~BulletManager();

    void Update();
    void Render(HDC hdc);

    void Fire(string key, Vector2 pos, Vector2 direction);

    void CreateBullets(string key, UINT poolingSize, Texture* texture);

    void IncreaseCount();

    vector<Bullet *> & GetBullets(string key) { return totalBullets[key]; }
private:
    typedef vector<Bullet *> Bullets;

    map<string, Bullets> totalBullets;

    HBRUSH brush;

    int count = 0;
};