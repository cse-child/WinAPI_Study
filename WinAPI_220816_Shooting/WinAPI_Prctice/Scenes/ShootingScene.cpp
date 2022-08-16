#include "Framework.h"
#include "ShootingScene.h"

ShootingScene::ShootingScene()
{
	Texture* planeBullet = TEXTURE->Add(L"Textures/Bullet.bmp", 54, 33);
	BulletManager::Get()->CreateBullets("Plane", 30, planeBullet);
	EnemyManager::Get()->CreateEnemies(50);

	landscape = new LandScape();
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
	EnemyManager::Get()->IsCollision(plane);
}

void ShootingScene::CollisionBulletAndEnemy()
{
	for (Bullet* bullet : BulletManager::Get()->GetBullets("Plane"))
	{
		if (EnemyManager::Get()->IsCollision(bullet))
		{
			bullet->Active() = false;
		}
	}
}
