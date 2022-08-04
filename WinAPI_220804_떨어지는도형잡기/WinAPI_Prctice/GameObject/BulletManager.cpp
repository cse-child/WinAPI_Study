#include "Framework.h"

BulletManager::BulletManager()
{
	brush = CreateSolidBrush(RGB(100, 100, 100));
}

BulletManager::~BulletManager()
{
	DeleteObject(brush);
}

void BulletManager::Update()
{
	for (Bullet* bullet : bullets)
		bullet->Update();
}

void BulletManager::Render(HDC hdc)
{
	for (Bullet* bullet : bullets)
		bullet->Render(hdc);

	wstring str = L"Count : " + to_wstring(count);
	TextOut(hdc, 0, 0, str.c_str(), (int)str.length());
}

void BulletManager::Fire(Vector2 pos)
{
	for (Bullet* bullet : bullets)
	{
		if (!bullet->IsActive())
		{
			bullet->Fire(pos);
			return;
		}
	}
}

void BulletManager::CreateBullets(UINT poolingSize)
{
	bullets.resize(poolingSize);

	// *&로 참조하지않고 *만 하게되면 for문이 끝날때
	// 생성된 Bullet 객체들이 bullets에 저장되지않고
	// 사라지기 때문에 객체들에는 여전히 null 만 남아있다.
	for (Bullet*& bullet : bullets)
	{
		bullet = new Bullet(brush);
	}
}

void BulletManager::IncreaseCount()
{
	count++;

	if (count > 10)
	{
		GameManager::Get()->Stop();

		MessageBox(GameManager::Get()->GetHWND(),
			L"GameOver", L"Result", MB_OK);

		PostQuitMessage(0);
	}
}
