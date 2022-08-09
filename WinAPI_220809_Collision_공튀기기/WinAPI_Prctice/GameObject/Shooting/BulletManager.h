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
	void Fire(Vector2 pos, Vector2 direction);

	void CreateBullets(UINT poolingSize);

	void IncreaseCount();

	vector<Bullet*>& GetBullets() { return bullets; }

private:
	vector<Bullet*> bullets;

	HBRUSH brush;

	int count;
};