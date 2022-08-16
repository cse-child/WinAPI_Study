#include "Framework.h"
#include "ShootingScene.h"

ShootingScene::ShootingScene()
{
	Texture* planeBullet = TEXTURE->Add(L"Textures/Bullet.bmp", 54, 33);
	BulletManager::Get()->CreateBullets("Plane", 30, planeBullet);

	Texture* enemyBullet = TEXTURE->Add(L"Textures/EnemyBullet.bmp", 54, 54);
	BulletManager::Get()->CreateBullets("Enemy", 50, enemyBullet);

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
	CollisionPlaneAndEnemyBullet();

	if (plane->GetHpBar()->GetHP() <= 0)
	{
		MessageBox(hWnd, L"GameOver", L"GameOver", MB_OK);
		PostQuitMessage(0);
	}
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
	for (Enemy* enemy : EnemyManager::Get()->GetEnemies())
	{
		if (plane->IsCollision(enemy))
		{
			plane->GetHpBar()->DecreaseHP(10);
			break;
		}
	}

	//if (EnemyManager::Get()->IsCollision(plane))
	//{
	//	plane->GetHpBar()->DecreaseHP(10);
	//}
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

	//enemy->GetHpBar()->DecreaseHP(10);

	//if (enemy->GetHpBar()->GetHP() <= 0)
	//	return true;
}

void ShootingScene::CollisionPlaneAndEnemyBullet() 
{
	for (Bullet* bullet : BulletManager::Get()->GetBullets("Enemy"))
	{
		if (plane->IsCollision(bullet))
		{
			bullet->Active() = false;
			plane->GetHpBar()->DecreaseHP(10);
		}
	}
}