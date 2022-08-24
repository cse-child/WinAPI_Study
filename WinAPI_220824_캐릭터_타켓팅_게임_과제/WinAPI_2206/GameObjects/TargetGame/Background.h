#pragma once

class Background : public ImageRect
{
public:
	Background();
	~Background();

	void Update();
	void Render(HDC hdc);

private:
	ImageRect* bgs[2];

	float speed = 50.0f;

};