#include "Framework.h"
#include "ShootingScene.h"

ShootingScene::ShootingScene()
{

    Texture* texture = TEXTURE->Add(L"Textures/Explosion.bmp", 512, 512, 4, 4);
    EffectManager::Get()->Add("exp", texture);

    texture = TEXTURE->Add(L"Textures/Explosion2.bmp", 516, 644, 4, 5);
    EffectManager::Get()->Add("exp2", texture);

    Texture * planeBullet = TEXTURE->Add(L"Textures/Bullet.bmp", 54, 33);
    BulletManager::Get()->CreateBullets("Plane", 30, planeBullet);

    Texture* enemyBullet = TEXTURE->Add(L"Textures/EnemyBullet.bmp", 54, 54);
    BulletManager::Get()->CreateBullets("Enemy", 50, enemyBullet);

    EnemyManager::Get()->CreateEnemies(50);

    landscape = new Landscape();
    plane = new Plane();

    EnemyManager::Get()->SetTarget(plane);

    Audio::Get()->Add("bgm", "Sounds/bgm.ogg", true);
    Audio::Get()->Add("fire", "Sounds/fire.wav", true);
    
    Audio::Get()->Play("bgm", 0.5f);
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
    CollisionBulletAndPlane();

    BulletManager::Get()->CollisionBullet("Plane", "Enemy");
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

            EffectManager::Get()->Play("exp", enemy->Pos());
        }
    }
}

void ShootingScene::CollisionBulletAndPlane()
{
    for (Bullet* bullet : BulletManager::Get()->GetBullets("Enemy"))
    {
        if (plane->IsCollision(bullet))
        {
            bullet->Active() = false;
            plane->Damage();

            EffectManager::Get()->Play("exp2", plane->Pos());
        }
    }

}
