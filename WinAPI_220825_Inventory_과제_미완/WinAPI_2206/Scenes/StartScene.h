#pragma once

class StartScene : public Scene
{
public:
	StartScene();
	~StartScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	void ChangeCameraScene();
	void SelectButton(void* obj);

private:
	Button* button;
	Button* button2;
};