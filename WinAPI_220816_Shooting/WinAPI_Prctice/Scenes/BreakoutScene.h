#pragma once

class BreakoutScene : public Scene
{
public:
	BreakoutScene();
	~BreakoutScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	ControlBar* controlBar;
	Ball* ball;
};