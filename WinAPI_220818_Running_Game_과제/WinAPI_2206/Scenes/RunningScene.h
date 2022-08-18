#pragma once

class RunningScene : public Scene
{
public:
	RunningScene();
	~RunningScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Cookie* cookie;
};