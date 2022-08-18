#pragma once

class ZombieRunScene : public Scene
{
public:
	ZombieRunScene();
	~ZombieRunScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	void CollisionCookieAndStool();
	void IsFallInToHole();

private:
	ZombieCookie* cookie;
	Background* bg;

	UINT score;

};