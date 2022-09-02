#pragma once

class CameraScene : public Scene
{
public:
	CameraScene();
	~CameraScene();

	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;

	virtual void Start() override;
	virtual void End() override;

private:
	ImageRect* land;

	Cookie* cookie;
};