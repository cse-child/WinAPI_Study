#include "Framework.h"
#include "BombGameScene.h"

BombGameScene::BombGameScene()
{
	background = new ImageRect(TEXTURE->Add(L"Textures/Sky.bmp", 1000, 600));
	background->Pos() = { CENTER_X, CENTER_Y };

	land = new ImageRect(TEXTURE->Add(L"Textures/Grass.bmp", 1000, 600));
	land->Pos() = { CENTER_X, CENTER_Y };

	cookie = new Cookie();
	cookie->SetLand(land->GetTexture());

	BombManager::Get()->CreateBombs(10);
	BombManager::Get()->SetLandTexture(land->GetTexture());

	KirbyEnemyManager::Get()->CreateEnemies(10);
	KirbyEnemyManager::Get()->SetLandTexture(land->GetTexture());
	
	Audio::Get()->Add("bomb", "Sounds/bomb.wav");
	EffectManager::Get()->Add("bomb", TEXTURE->Add(L"Textures/Explosion3.bmp", 519, 65, 8, 1));
}

BombGameScene::~BombGameScene()
{
	delete background;
	delete land;
	delete cookie;

	BombManager::Delete();
	KirbyEnemyManager::Delete();
}

void BombGameScene::Update()
{
	cookie->Update();
	BombManager::Get()->Update();
	KirbyEnemyManager::Get()->Update();
	KirbyEnemyManager::Get()->SetPlayerPos(cookie->Pos());

	CollisionBombAndEnemy();
}

void BombGameScene::Render(HDC hdc)
{
	background->Render(hdc);
	land->Render(hdc);
	cookie->Render(hdc);
	BombManager::Get()->Render(hdc);
	KirbyEnemyManager::Get()->Render(hdc);
}

void BombGameScene::CollisionBombAndEnemy()
{
	//if(BombManager::Get()->IsPlant())
	//	KirbyEnemyManager::Get()->CollisionExplodeCircle(BombManager::Get()->GetExplodeCircle());
}