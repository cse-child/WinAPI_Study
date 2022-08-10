#include "Framework.h"
#include "BreakoutScene.h"

BreakoutScene::BreakoutScene()
{
	controlBar = new ControlBar();
	ball = new Ball();
	ball->SetBarRect(controlBar);
	BrickManager::Get();
	BrickManager::Get()->SetBall(ball);
}

BreakoutScene::~BreakoutScene()
{
	delete controlBar;
	delete ball;
	BrickManager::Delete();
}

void BreakoutScene::Update()
{
	controlBar->Update();
	ball->Update();
}

void BreakoutScene::Render(HDC hdc)
{
	controlBar->Render(hdc);
	ball->Render(hdc);
	BrickManager::Get()->Render(hdc);
}
