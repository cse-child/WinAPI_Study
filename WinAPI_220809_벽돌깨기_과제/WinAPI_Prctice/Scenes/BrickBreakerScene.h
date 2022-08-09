#pragma once

class BrickBreakerScene : public Scene
{
public:
	BrickBreakerScene();
	~BrickBreakerScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	BrickBreaker* controlBar;
};