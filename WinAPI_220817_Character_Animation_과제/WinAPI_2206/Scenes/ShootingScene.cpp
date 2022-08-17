#include "Framework.h"
#include "ShootingScene.h"

ShootingScene::ShootingScene()
{
    Texture * planeBullet = TEXTURE->Add(L"Textures/Bullet.bmp", 54, 33);
    BulletManager::Get()->CreateBullets("Plane", 30, planeBullet);

    EnemyManager::Get()->CreateEnemies(50);

    landscape = new Landscape();
    plane = new Plane();
}

ShootingScene::~ShootingScene()
{
    delete landscape;
    delete plane;

    BulletManager::Delete();
    EnemyManager::Delete();
}

void ShootingScene::Update()
{
    landscape->Update();
    plane->Update();

    BulletManager::Get()->Update();
    EnemyManager::Get()->Update();

    CollisionPlaneAndEnemy();
    CollisionBulletAndEnemy();
}

void ShootingScene::Render(HDC hdc)
{
    landscape->Render(hdc);
    plane->Render(hdc);

    BulletManager::Get()->Render(hdc);
    EnemyManager::Get()->Render(hdc);
}

void ShootingScene::CollisionPlaneAndEnemy()
{
    Enemy* enemy = EnemyManager::Get()->IsCollision(plane);
    
    if (enemy == nullptr) return;

    plane->Damage();
    enemy->Active() = false;
}

void ShootingScene::CollisionBulletAndEnemy()
{
    for (Bullet * bullet : BulletManager::Get()->GetBullets("Plane"))
    {
        Enemy* enemy = EnemyManager::Get()->IsCollision(bullet);

        if (enemy)
        {
            bullet->Active() = false;
            enemy->Damage();
        }
    }
}
