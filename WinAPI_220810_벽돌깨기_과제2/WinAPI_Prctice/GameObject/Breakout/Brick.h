#pragma once

class Brick : public Rect
{
private:
	const UINT MAX_HP = 4;

public:
	Brick(Vector2 pos, Vector2 size, int hp = 1);
	~Brick();

	void Render(HDC hdc);

	Direction Collision(Circle* circle);

private:
	int hp;

	vector<HBRUSH> hBrushes;
};