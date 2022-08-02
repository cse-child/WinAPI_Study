#pragma once

class BulletManager : public Singleton<BulletManager>
{
public:
	BulletManager();
	~BulletManager();

	void Update();
	void Render(HDC hdc);

	void Fire(POINT pos);

	void CreateBullets(UINT poolingSize);

	void IncreaseCount();

private:
	vector<Bullet*> bullets;

	HBRUSH brush;

	int count;
};