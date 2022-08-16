#pragma once

class AngleScene : public Scene
{
public:
	AngleScene();
	~AngleScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Cannon* cannon;
};