#include "Framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	//circle = new Circle({500, 500},100);
	circles.push_back(new Circle({(int)CENTER_X, (int)CENTER_Y}, 100));
}

TutorialScene::~TutorialScene()
{
	//delete circle;
	for (Circle* circle : circles)
		delete circle;
}

void TutorialScene::Update()
{
	frameCount++;
	
	//if (GetAsyncKeyState(VK_LBUTTON))
	//{
	//	circles.push_back(new Circle(mousePos, 100));
	//}

	// 키가 눌러졌는지 아닌지 확인
	if (GetAsyncKeyState(VK_RIGHT))
	{
		circles[0]->Pos().x += 10;
		//InvalidateRect(GameManager::Get()->GetHWND(), nullptr, true);
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		circles[0]->Pos().x -= 10;
		//InvalidateRect(GameManager::Get()->GetHWND(), nullptr, true);
	}
	if (GetAsyncKeyState(VK_UP))
	{
		circles[0]->Pos().y -= 10;
		//InvalidateRect(GameManager::Get()->GetHWND(), nullptr, true);
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		circles[0]->Pos().y += 10;
		//InvalidateRect(GameManager::Get()->GetHWND(), nullptr, true);
	}
	
}

void TutorialScene::Render(HDC hdc)
{
	wstring str = L"FrameCount : " + to_wstring(frameCount);
	TextOut(hdc, 0, 0, str.c_str(), str.length());

	//circle->Render(hdc);

	for (Circle* circle : circles)
		circle->Render(hdc);
}
