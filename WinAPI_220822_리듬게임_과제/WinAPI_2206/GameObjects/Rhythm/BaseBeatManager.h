#pragma once

class BaseBeatManager : public Singleton<BaseBeatManager>
{
//public:
//	enum BeatType
//	{
//		UP, DOWN, LEFT, RIGHT, MAX
//	};

private:
	const UINT BEAT_COUNT = 4;

public:
	BaseBeatManager();
	~BaseBeatManager();

	void Update();
	void Render(HDC hdc);

	Vector2 GetPos(NoteBeat::BeatType type) { return beats[type]->Pos(); }

	bool IsCollision(Rect* rect, NoteBeat::BeatType type);

private:
	vector<ImageRect*> beats;
};