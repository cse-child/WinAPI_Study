#include "Framework.h"
#include "InventoryScene.h"

InventoryScene::InventoryScene()
{
	store = new Store();
	inventory = new Inventory();
}

InventoryScene::~InventoryScene()
{
	delete store;
	delete inventory;
}

void InventoryScene::Update()
{
	store->Update();
	inventory->Update();
}

void InventoryScene::Render(HDC hdc)
{
	store->Render(hdc);
	inventory->Render(hdc);
}
