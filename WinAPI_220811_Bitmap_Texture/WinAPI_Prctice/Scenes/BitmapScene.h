#pragma once

class BitmapScene : public Scene
{
public:
	BitmapScene();
	~BitmapScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	HDC memDC;
	HBITMAP bitmap;
	HBITMAP sivaBitmap;

	Siva* siva;
};