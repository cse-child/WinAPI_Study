#include "Framework.h"

#include "Scenes/BrickBreakerScene.h"


GameManager::GameManager()
{
	Create();
	scene = new BrickBreakerScene();
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

	scene->Update();
}

void GameManager::Render()
{
	// Back buffer�� ������� �׸��� �׷��ְڴ�.
	PatBlt(backBuffer, 0, 0, WIN_WIDTH, WIN_HEIGHT, WHITENESS);

	scene->Render(backBuffer); // �켱 ��ȭ���� �׸� �׸���

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

void GameManager::Create()
{
	Keyboard::Get();
}

void GameManager::Delete()
{
	Keyboard::Delete();
}
