#pragma once

class PlaneScene : public Scene
{
public:
	PlaneScene();
	~PlaneScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Plane* plane;
};