#include "Framework.h"
#include "FallShapeScene.h"

FallShapeScene::FallShapeScene()
{
	ObjectManager::Get()->CreateObject(POOLING_SIZE);
}

FallShapeScene::~FallShapeScene()
{
	ObjectManager::Delete();
}

void FallShapeScene::Update()
{
	ObjectManager::Get()->Update();
}

void FallShapeScene::Render(HDC hdc)
{
	ObjectManager::Get()->Render(hdc);
}
