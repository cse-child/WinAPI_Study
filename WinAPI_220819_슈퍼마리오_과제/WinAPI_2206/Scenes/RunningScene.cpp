#include "Framework.h"
#include "RunningScene.h"

RunningScene::RunningScene()
{
	landscape = new Landscape();
	cookie = new Cookie();

	LandManager::Get();
}

RunningScene::~RunningScene()
{
	delete landscape;
	delete cookie;

	LandManager::Delete();
}

void RunningScene::Update()
{
	landscape->Update();
	cookie->Update();

	LandManager::Get()->Update();
}

void RunningScene::Render(HDC hdc)
{
	landscape->Render(hdc);
	cookie->Render(hdc);

	LandManager::Get()->Render(hdc);
}
