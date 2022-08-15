#pragma once

class BrickManager : public Singleton<BrickManager>
{
public:
	BrickManager();
	~BrickManager();

	void Render(HDC hdc);

	Direction Collision(Circle* circle);

	void CreateStage();
	void ClearStage();

private:
	vector<Brick*> bricks;
};