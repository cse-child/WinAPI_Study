#include "Framework.h"
#include "DropScene.h"

DropScene::DropScene()
{
	DropManager::Get()->CreateCircles(50);
}

DropScene::~DropScene()
{
	DropManager::Get()->Delete();
}

void DropScene::Update()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		DropManager::Get()->Drop();
	}
	DropManager::Get()->Update();
}

void DropScene::Render(HDC hdc)
{
	DropManager::Get()->Render(hdc);
}
