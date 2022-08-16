#include "Framework.h"

BulletManager::BulletManager()
{
	brush = CreateSolidBrush(RGB(100, 100, 100));
}

BulletManager::~BulletManager()
{
	DeleteObject(brush);

	for (pair<string, Bullets> bullets : totalBullets)
	{
		for (Bullet* bullet : bullets.second)
			delete bullet;
	}
}

void BulletManager::Update()
{		
	for (pair<string, Bullets> bullets : totalBullets)
	{
		for (Bullet* bullet : bullets.second)
			bullet->Update();
	}
}

void BulletManager::Render(HDC hdc)
{
	for (pair<string, Bullets> bullets : totalBullets)
	{
		for (Bullet* bullet : bullets.second)
			bullet->Render(hdc);
	}
	
	wstring str = L"Count : " + to_wstring(count);
	TextOut(hdc, 0, 0, str.c_str(), (int)str.length());
}

void BulletManager::Fire(string key, Vector2 pos, Vector2 direction)
{
	if (totalBullets.count(key) == 0) 
		return;

	Bullets bullets = totalBullets[key];

	for (Bullet* bullet : bullets)
	{
		if (!bullet->Active())
		{
			bullet->Fire(pos, direction);
			return;
		}
	}
}

void BulletManager::CreateBullets(string key, UINT poolingSize, Texture* texture)
{
	if (totalBullets.count(key) > 0)
		return;

	vector<Bullet*> bullets;
	bullets.resize(poolingSize);

	// *&로 참조하지않고 *만 하게되면 for문이 끝날때
	// 생성된 Bullet 객체들이 bullets에 저장되지않고
	// 사라지기 때문에 객체들에는 여전히 null 만 남아있다.
	for (Bullet*& bullet : bullets)
	{
		bullet = new Bullet(texture);
	}

	totalBullets[key] = bullets;
}

void BulletManager::IncreaseCount()
{
	count++;

	if (count > 10)
	{
		GameManager::Get()->Stop();

		MessageBox(hWnd,L"GameOver", L"Result", MB_OK);

		PostQuitMessage(0);
	}
}
