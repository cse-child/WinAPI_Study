#pragma once

class BombGameScene : public Scene
{
public:
	BombGameScene();
	~BombGameScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void CollisionBombAndEnemy();

private:
	ImageRect* background;
	ImageRect* land;

	Cookie* cookie;
};