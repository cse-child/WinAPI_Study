#include "Framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	//circle = new Circle({500, 500},100);
	//srand(time(NULL));
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
	
	randomPos.x = rand() % 1280 + 1;
	randomPos.y = rand() % 600 + 1;
	circles.push_back(new Circle(randomPos, rand() % 100 + 1));

	//if (GetAsyncKeyState(VK_LBUTTON))
	//{
	//	circles.push_back(new Circle(mousePos, 100));
	//
	//}

	// 키가 눌러졌는지 아닌지 확인
	//if (GetAsyncKeyState(VK_RIGHT))
	//{
	//	circle->Pos().x += 10;
	//	InvalidateRect(GameManager::Get()->GetHWND(), nullptr, true);
	//}
	//if (GetAsyncKeyState(VK_LEFT))
	//{
	//	circle->Pos().x -= 10;
	//	InvalidateRect(GameManager::Get()->GetHWND(), nullptr, true);
	//}
	
}

void TutorialScene::Render(HDC hdc)
{
	wstring str = L"FrameCount : " + to_wstring(frameCount);
	TextOut(hdc, 0, 0, str.c_str(), str.length());

	str = L"Circle Pos : " + to_wstring(randomPos.x) + L", "+ to_wstring(randomPos.y)+L"              ";
	TextOut(hdc, 0, 20, str.c_str(), str.length());

	//circle->Render(hdc);

	for (Circle* circle : circles)
		circle->Render(hdc);
}
