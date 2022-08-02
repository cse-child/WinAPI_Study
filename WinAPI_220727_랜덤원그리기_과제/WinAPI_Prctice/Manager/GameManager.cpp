#include "Framework.h"

#include "Scenes/TutorialScene.h"


GameManager::GameManager()
	:hWnd(hWnd), hdc(hdc)
{
	scene = new TutorialScene();
}

GameManager::~GameManager()
{
}

void GameManager::Update()
{
	scene->Update();
}

void GameManager::Render()
{
	//InvalidateRect(hWnd, nullptr, true);
	scene->Render(hdc);
}

void GameManager::SetHWND(HWND hWnd)
{
	this->hWnd = hWnd;
	hdc = GetDC(hWnd);
}
