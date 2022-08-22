#pragma once

class NoteBeat : public ImageRect
{
public:
	enum BeatType
	{
		UP, DOWN, LEFT, RIGHT, NONE
	};

private:
	const int BEAT_COUNT = 4;

public:
	NoteBeat();
	~NoteBeat();

	void Update();
	void Render(HDC hdc);

	void Init();

private:
	BeatType beatType;

	float speed = 400.0f;
};