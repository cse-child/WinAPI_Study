#include "Framework.h"

#include "Scenes/PlaneScene.h"
#include "Scenes/DropScene.h"


GameManager::GameManager()
{
	//scene = new PlaneScene();
	scene = new DropScene();
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
	// Back buffer에 흰색으로 그림을 그려주겠다.
	PatBlt(backBuffer, 0, 0, WIN_WIDTH, WIN_HEIGHT, WHITENESS);

	scene->Render(backBuffer); // 우선 도화지에 그림 그리기

	// back buffer 출력하기
	BitBlt(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, 
		backBuffer, 0, 0, SRCCOPY);
}

void GameManager::SetInit(HWND hWnd)
{
	this->hWnd = hWnd;
	hdc = GetDC(hWnd);

	// 윈도우 창 크기의 흰색 도화지를 만듬
	backBuffer = CreateCompatibleDC(hdc);
	bitmap = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);
	SelectObject(backBuffer, bitmap);
}
