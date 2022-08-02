#pragma once

class BulletScene : public Scene
{
public:
	const UINT MAX_BULLET_COUNT = 20;

public:
	BulletScene();
	~BulletScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	void Shoot();

private:
	vector<Bullet*> bullets;

	UINT spawnTime = 15;
	UINT playTime = 0;

	POINT pos;
};