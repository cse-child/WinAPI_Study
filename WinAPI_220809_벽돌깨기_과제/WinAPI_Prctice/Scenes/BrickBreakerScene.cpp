#include "Framework.h"
#include "BrickBreakerScene.h"

BrickBreakerScene::BrickBreakerScene()
{
	controlBar = new BrickBreaker();

}

BrickBreakerScene::~BrickBreakerScene()
{
	delete controlBar;
}

void BrickBreakerScene::Update()
{
	controlBar->Update();
}

void BrickBreakerScene::Render(HDC hdc)
{
	controlBar->Render(hdc);
}
