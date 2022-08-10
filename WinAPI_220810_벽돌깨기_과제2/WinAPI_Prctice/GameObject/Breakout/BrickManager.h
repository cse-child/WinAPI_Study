#pragma once

class BrickManager : public Singleton<BrickManager>
{
public:
	BrickManager();
	~BrickManager();

	void Render(HDC hdc);

	Direction Collision(Circle* circle);

	void CreateStage();
	void CreateStage2();
	void ClearStage();

	void DecreaseBrickCount();

	void SetBall(Ball* ball) { this->ball = ball; }

private:
	vector<Brick*> bricks;
	UINT totalBrick;
	Ball* ball;

	bool stage1Clear = false;
};