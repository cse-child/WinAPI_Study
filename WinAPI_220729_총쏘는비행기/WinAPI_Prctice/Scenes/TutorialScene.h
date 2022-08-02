#pragma once

class TutorialScene : public Scene
{
public:
	TutorialScene();
	~TutorialScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	UINT frameCount = 0;

	//Circle* circle;
	vector<Circle*> circles;

};