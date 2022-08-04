#pragma once

class BulletManager : public Singleton<BulletManager>
{
public:
	BulletManager();
	~BulletManager();

	void Update();
	void Render(HDC hdc);

	void Fire(Vector2 pos);

	void CreateBullets(UINT poolingSize);

	void IncreaseCount();

	vector<Bullet*> GetBullets() { return bullets; }

	void BulletCollision();

private:
	vector<Bullet*> bullets;

	HBRUSH brush;

	int count;
};