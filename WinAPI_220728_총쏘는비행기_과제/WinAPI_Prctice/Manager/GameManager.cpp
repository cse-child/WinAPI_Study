#include "Framework.h"

#include "Scenes/TutorialScene.h"
#include "Scenes/SpawnScene.h"
#include "Scenes/PlaneScene.h"
#include "Scenes/BulletScene.h"


GameManager::GameManager()
{
	//scene = new TutorialScene();
	//scene = new SpawnScene();
	scene = new PlaneScene();
	bulletScene = new BulletScene();
}

GameManager::~GameManager()
{
	delete scene;
	delete bulletScene;
}

void GameManager::Update()
{
	scene->Update();
	bulletScene->Update();
}

void GameManager::Render()
{
	// Back buffer�� ������� �׸��� �׷��ְڴ�.
	PatBlt(backBuffer, 0, 0, WIN_WIDTH, WIN_HEIGHT, WHITENESS);

	scene->Render(backBuffer); // �켱 ��ȭ���� �׸� �׸���
	bulletScene->Render(backBuffer);

	// back buffer ����ϱ�
	BitBlt(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, 
		backBuffer, 0, 0, SRCCOPY);
}

void GameManager::SetInit(HWND hWnd)
{
	this->hWnd = hWnd;
	hdc = GetDC(hWnd);

	// ������ â ũ���� ��� ��ȭ���� ����
	backBuffer = CreateCompatibleDC(hdc);
	bitmap = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);
	SelectObject(backBuffer, bitmap);
}
