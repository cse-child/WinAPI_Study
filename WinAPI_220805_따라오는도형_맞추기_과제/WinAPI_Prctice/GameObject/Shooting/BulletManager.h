#pragma once

class BulletManager : public Singleton<BulletManager>
{
public:
	BulletManager();
	~BulletManager();

	void Update();
	void Render(HDC hdc);

	void Fire(Vector2 pos);
	void Fire(Vector2 pos, float angle);

	void CreateBullets(UINT poolingSize);

	void IncreaseCount();

	vector<Bullet*>& GetBullets() { return bullets; }

private:
	vector<Bullet*> bullets;

	HBRUSH brush;

	int count;

	float playTime = 0.0f;
	float bulletSpawnTime = 10.0f;
};