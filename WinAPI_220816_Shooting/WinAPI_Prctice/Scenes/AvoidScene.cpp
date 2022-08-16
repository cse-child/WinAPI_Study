#include "Framework.h"
#include "AvoidScene.h"

AvoidScene::AvoidScene()
{
	player = new AvoidPlayer();

	DropManager::Get()->CreateCircles(100);
	DropManager::Get()->SetTarget(player);
}

AvoidScene::~AvoidScene()
{
	delete player;
	DropManager::Delete();
}

void AvoidScene::Update()
{
	player->Update();
	DropManager::Get()->Update();

}

void AvoidScene::Render(HDC hdc)
{
	player->Render(hdc);
	DropManager::Get()->Render(hdc);
}
