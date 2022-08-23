#include "Framework.h"

BombManager::BombManager()
{
	hBrush = CreateSolidBrush(MAGENTA);
	hPen = CreatePen(PS_SOLID, 1, MAGENTA);
}

BombManager::~BombManager()
{
	DeleteObject(hBrush);
	DeleteObject(hPen);

	for (Bomb* bomb : bombs)
		delete bomb;
	bombs.clear();
}

void BombManager::Update()
{
	for (Bomb* bomb : bombs)
		bomb->Update();
}

void BombManager::Render(HDC hdc)
{
	for (Bomb* bomb : bombs)
		bomb->Render(hdc);
}

void BombManager::PlantBomb(Vector2 pos)
{
	for (Bomb* bomb : bombs)
	{
		if (!bomb->Active()) {
			bomb->PlantBomb();
			bomb->Pos() = pos;
			bomb->Pos().y += 50.0f;
			//KirbyEnemyManager::Get()->CollisionExplodeCircle(bomb->GetExplodeCircle());
			//isPlant = true;
			return;
		}
	}
}

void BombManager::CreateBombs(UINT poolingCount)
{
	bombs.resize(poolingCount);

	for (Bomb*& bomb : bombs)
	{
		bomb = new Bomb(hBrush, hPen);
	}
}

void BombManager::SetLandTexture(Texture* texture)
{
	for (Bomb* bomb : bombs)
	{
		bomb->SetLandTexture(texture);
	}
}


Circle* BombManager::GetExplodeCircle()
{
	return bombs[0]->GetExplodeCircle();
}