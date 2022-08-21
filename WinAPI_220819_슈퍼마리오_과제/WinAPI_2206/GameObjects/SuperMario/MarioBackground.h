#pragma once

class MarioBackground
{
public:
	MarioBackground();
	~MarioBackground();

	void Update();
	void Render(HDC hdc);

private:
	ImageRect* bgs[2];

	float speed = 50;
};