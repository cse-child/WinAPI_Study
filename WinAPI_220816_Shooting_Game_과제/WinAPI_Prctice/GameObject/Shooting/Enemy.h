#pragma once

class Enemy : public ImageRect
{
public:
	Enemy();
	~Enemy();

	void Update();

	void Init();

	HpBar* GetHpBar() { return hpBar; }

private:
	void Move();
	void Fire();

private:
	float speed = 300.0f;
	Vector2 firePos;

	float playTime = 0.0f;
	float spawnTime = 1.0f;

	HpBar* hpBar;
};