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

	// *&�� ���������ʰ� *�� �ϰԵǸ� for���� ������
	// ������ Bullet ��ü���� bullets�� ��������ʰ�
	// ������� ������ ��ü�鿡�� ������ null �� �����ִ�.
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
