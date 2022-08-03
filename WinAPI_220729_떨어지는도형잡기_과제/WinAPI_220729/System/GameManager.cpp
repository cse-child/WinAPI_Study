#include "Framework.h"

#include "Scene/FallShapeScene.h"

GameManager::GameManager()
{
	scene = new FallShapeScene();
}

GameManager::~GameManager()
{
	delete scene;
}

void GameManager::Update()
{
	if (isStop) return;
	scene->Update();
}

void GameManager::Render()
{
	PatBlt(backBuffer, 0, 0, WIN_WIDTH, WIN_HEIGHT, WHITENESS);
	
	scene->Render(backBuffer);

	BitBlt(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, backBuffer, 0, 0, SRCCOPY);
}

void GameManager::SetInit(HWND hWnd)
{
	this->hWnd = hWnd;
	hdc = GetDC(hWnd);

	backBuffer = CreateCompatibleDC(hdc);
	bitmap = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);
	SelectObject(backBuffer, bitmap);
}
