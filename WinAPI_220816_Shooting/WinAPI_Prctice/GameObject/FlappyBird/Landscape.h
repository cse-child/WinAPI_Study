#pragma once

class LandScape
{
public:
	LandScape();
	~LandScape();

	void Update();
	void Render(HDC hdc);

private:
	ImageRect* bgs[2];

	float speed = 50.0f;
};