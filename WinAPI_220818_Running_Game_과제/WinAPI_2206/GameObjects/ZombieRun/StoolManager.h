#pragma once

class StoolManager : public Singleton<StoolManager>
{
private:
	const UINT STOOL_NUM = 6;

	const float MIN_STOOL_WIDTH = 500.0f;
	const float MAX_STOOL_WIDTH = 800.0f ;
					
	const float STOOL_HEIGHT = WIN_HEIGHT - 100.0f;

	//const float MIN_STOOL_HEIGHT = WIN_HEIGHT - 100.0f;
	//const float MAX_STOOL_HEIGHT = CENTER_Y + 100.0f;

public:
	StoolManager();
	~StoolManager();

	void Update();
	void Render(HDC hdc);

	ImageRect* IsCollision(Rect* rect);

private:
	void CreateStools();

private:
	vector<ImageRect*> stools;

	Texture* texture;

	float speed = 400.0f;

	//Vector2 interval = { 300, 0 };

	bool isStart = false;
};