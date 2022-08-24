#include "Framework.h"

LandManager::LandManager()
{
	for (UINT i = 0; i < 10; i++)
	{
		Land* land = new Land();
		land->Pos().x = land->Size().x * i + land->Half().x;
		land->Pos().y = WIN_HEIGHT - land->Half().y;

		lands.push_back(land);
	}

	for (UINT i = 0; i < 5; i++)
	{
		Land* land = new Land();
		land->Pos().x = land->Size().x * i + 300;
		land->Pos().y = WIN_HEIGHT - 400;

		lands.push_back(land);
	}
}

LandManager::~LandManager()
{
	for (Land* land : lands)
		delete land;

	lands.clear();
}

void LandManager::Update()
{
	for (Land* land : lands)
		land->Update();
}

void LandManager::Render(HDC hdc)
{
	for (Land* land : lands)
		land->Render(hdc);
}

Rect* LandManager::IsCollision(Rect* rect)
{
	for (Land* land : lands)
	{
		if (land->IsCollision(rect))
			return land;
	}
	return nullptr;
}
