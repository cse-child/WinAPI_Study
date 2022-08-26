#include "Framework.h"
#include "InventoryScene.h"

InventoryScene::InventoryScene()
{
	store = new Store();
}

InventoryScene::~InventoryScene()
{
	delete store;
}

void InventoryScene::Update()
{
	store->Update();
}

void InventoryScene::Render(HDC hdc)
{
	store->Render(hdc);
}
