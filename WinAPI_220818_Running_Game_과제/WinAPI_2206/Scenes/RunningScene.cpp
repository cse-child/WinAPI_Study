#include "Framework.h"
#include "RunningScene.h"

RunningScene::RunningScene()
{
	cookie = new Cookie();
}

RunningScene::~RunningScene()
{
	delete cookie;
}

void RunningScene::Update()
{
	cookie->Update();
}

void RunningScene::Render(HDC hdc)
{
	cookie->Render(hdc);
}
