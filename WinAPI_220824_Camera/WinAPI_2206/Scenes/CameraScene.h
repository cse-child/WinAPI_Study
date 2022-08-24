#pragma once

class CameraScene : public Scene
{
public:
	CameraScene();
	~CameraScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	ImageRect* land;

	Cookie* cookie;
};