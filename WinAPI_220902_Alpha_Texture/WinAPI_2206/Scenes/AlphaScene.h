#pragma once

class AlphaScene : public Scene
{
public:
	AlphaScene();
	~AlphaScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	ImageRect* test;
	ImageRect* cat;

	float alpha = 0;
	float speed = 100;
};