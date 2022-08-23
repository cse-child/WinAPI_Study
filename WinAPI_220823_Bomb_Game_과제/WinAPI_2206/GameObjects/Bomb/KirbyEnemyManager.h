#pragma once

class KirbyEnemyManager : public Singleton<KirbyEnemyManager>
{
public:
	KirbyEnemyManager();
	~KirbyEnemyManager();

	void Update();
	void Render(HDC hdc);

	void Drop();

	void CreateEnemies(UINT poolingCount);

	void SetLandTexture(Texture* texture);
	void SetPlayerPos(Vector2 pos);

	void CollisionExplodeCircle(Circle* circle);

private:
	vector<KirbyEnemy*> enemies;

	float playTime;
	float spawnTime = 2.0f;
};