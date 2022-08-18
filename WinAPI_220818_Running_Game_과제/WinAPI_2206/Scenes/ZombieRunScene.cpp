#include "Framework.h"
#include "ZombieRunScene.h"

ZombieRunScene::ZombieRunScene()
{
	bg = new Background();
	cookie = new ZombieCookie();

	StoolManager::Get();
}

ZombieRunScene::~ZombieRunScene()
{
	delete bg;
	delete cookie;

	StoolManager::Delete();
}

void ZombieRunScene::Update()
{
	bg->Update();
	cookie->Update();

	StoolManager::Get()->Update();

	CollisionCookieAndStool();
	IsFallInToHole();

	if (score >= 5000)
	{
		GameManager::Get()->Stop();
		MessageBox(hWnd, L"목표점수(5000점)에 도달하셨습니다!\nGame Clear!", L"Game Clear", MB_OK);
		PostQuitMessage(0);
	}
}

void ZombieRunScene::Render(HDC hdc)
{
	bg->Render(hdc);
	cookie->Render(hdc);

	StoolManager::Get()->Render(hdc);

	wstring str = L"Score : " + to_wstring(score);
	TextOut(hdc, CENTER_X, 0, str.c_str(), str.length());
}

void ZombieRunScene::CollisionCookieAndStool()
{
	ImageRect* stool = StoolManager::Get()->IsCollision(cookie->GetCollisionRect());
	
	if (stool == nullptr) return;

	cookie->Pos().y = stool->Pos().y - stool->Size().y * 0.5f - cookie->Size().y*0.5f;
	cookie->SetLanding();
	score += 10;
}

void ZombieRunScene::IsFallInToHole()
{
	if (cookie->Top() >= WIN_HEIGHT)
	{
		GameManager::Get()->Stop();
		MessageBox(hWnd, L"Game Over..", L"Game Over", MB_OK);
		PostQuitMessage(0);
	}
}
