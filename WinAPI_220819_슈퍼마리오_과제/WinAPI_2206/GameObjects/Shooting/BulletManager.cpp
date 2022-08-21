#include "Framework.h"

BulletManager::BulletManager()
{
    brush = CreateSolidBrush(RGB(255, 0, 0));
}

BulletManager::~BulletManager()
{
    DeleteObject(brush);

    for (pair<string, Bullets> bullets : totalBullets)
    {
        for (Bullet * bullet : bullets.second)
            delete bullet;
    }
}

void BulletManager::Update()
{
    for (pair<string, Bullets> bullets : totalBullets)
    {
        for (Bullet * bullet : bullets.second)
            bullet->Update();
    }
}

void BulletManager::Render(HDC hdc)
{
    for (pair<string, Bullets> bullets : totalBullets)
    {
        for (Bullet * bullet : bullets.second)
            bullet->Render(hdc);
    }

    wstring str = L"Count : " + to_wstring(count);
    TextOut(hdc, 0, 0, str.c_str(), (int)str.length());
}

void BulletManager::Fire(string key, Vector2 pos, Vector2 direction)
{
    if (totalBullets.count(key) == 0)
        return;

    Bullets bullets = totalBullets[key];

    for (Bullet * bullet : bullets)
    {
        if (!bullet->Active())
        {
            bullet->Fire(pos, direction);
            return;
        }
    }
}

void BulletManager::CollisionBullet(string key1, string key2)
{
    if (totalBullets.count(key1) == 0) return;
    if (totalBullets.count(key2) == 0) return;

    for (Bullet* bullet1 : totalBullets[key1])
    {
        for (Bullet* bullet2 : totalBullets[key2])
        {
            if (bullet1->IsCollision(bullet2))
            {
                bullet1->Active() = false;
                bullet2->Active() = false;
            }
        }
    }
}

void BulletManager::CreateBullets(string key, UINT poolingSize, Texture * texture)
{
    if (totalBullets.count(key) > 0)
        return;

    vector<Bullet *> bullets;

    bullets.resize(poolingSize);

    for (Bullet *& bullet : bullets)
    {
        bullet = new Bullet(texture);
    }

    totalBullets[key] = bullets;
}

void BulletManager::IncreaseCount()
{
    count++;

    if (count > 10)
    {
        GameManager::Get()->Stop();

        MessageBox(hWnd, L"GameOver", L"Result", MB_OK);

        PostQuitMessage(0);
    }
}
