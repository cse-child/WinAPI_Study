#include "Framework.h"

#include "Scenes/PlaneScene.h"
#include "Scenes/DropScene.h"
#include "Scenes/AngleScene.h"
#include "Scenes/AvoidScene.h"
#include "Scenes/CollisionScene.h"
#include "Scenes/BreakoutScene.h"
#include "Scenes/BitmapScene.h"


GameManager::GameManager()
{
	Create();
	//scene = new PlaneScene();
	//scene = new DropScene();
	//scene = new AngleScene();
	//scene = new AvoidScene();
	//scene = new CollisionScene();
	//scene = new BreakoutScene();
	scene = new BitmapScene();
}

GameManager::~GameManager()
{
	delete scene;

	Delete();
}

void GameManager::Update()
{
	if (isStop) return;

	Keyboard::Get()->Update();
	Timer::Get()->Update();

	scene->Update();
}

void GameManager::Render()
{
	// Back buffer에 흰색으로 그림을 그려주겠다.
	PatBlt(backBuffer, 0, 0, WIN_WIDTH, WIN_HEIGHT, WHITENESS);

	scene->Render(backBuffer); // 우선 도화지에 그림 그리기

	Timer::Get()->Render(backBuffer);

	// back buffer 출력하기
	BitBlt(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, 
		backBuffer, 0, 0, SRCCOPY);
}

void GameManager::SetInit()
{
	hdc = GetDC(hWnd);

	// 윈도우 창 크기의 흰색 도화지를 만듬
	backBuffer = CreateCompatibleDC(hdc);
	bitmap = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);
	SelectObject(backBuffer, bitmap);
}

void GameManager::Create()
{
	Keyboard::Get();
	Timer::Get();
}

void GameManager::Delete()
{
	Keyboard::Delete();
	Timer::Delete();
}
