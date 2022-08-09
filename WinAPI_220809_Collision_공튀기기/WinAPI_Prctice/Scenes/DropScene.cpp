#include "Framework.h"
#include "DropScene.h"

DropScene::DropScene()
{
	DropManager::Get()->CreateCircles(50);

	plane = new Plane();
}

DropScene::~DropScene()
{
	DropManager::Get()->Delete();
	delete plane;
}

void DropScene::Update()
{
	//if (GetAsyncKeyState(VK_SPACE))
	//{
	//	DropManager::Get()->Drop();
	//}

	DropManager::Get()->Update();

	plane->Update();

	CollisionBulletAndDropCircle();
}

void DropScene::Render(HDC hdc)
{
	DropManager::Get()->Render(hdc);
	
	plane->Render(hdc);

	wstring str = L"Score : " + to_wstring(score);
	TextOut(hdc, CENTER_X, 0, str.c_str(), str.length());
}

void DropScene::CollisionBulletAndDropCircle()
{
	for (Bullet* bullet : BulletManager::Get()->GetBullets())
	{
		if (!bullet->Active()) continue;
		
		if (DropManager::Get()->IsCollision(bullet))
		{
			score += 10;
			bullet->Active() = false;
		}
	}
}
