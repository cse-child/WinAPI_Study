#pragma once

class NoteBeatManager : public Singleton<NoteBeatManager>
{
//private:
//	enum BeatType
//	{
//		UP, DOWN, LEFT, RIGHT, MAX
//	};

public:
	NoteBeatManager();
	~NoteBeatManager();

	void Update();
	void Render(HDC hdc);

	void CreateNoteBeats(UINT poolingCount);

	vector<NoteBeat*> GetBeats() { return beats; }

private:
	void Spawn();

private:
	vector<NoteBeat*> beats;

	float playTime = 0.0f;
	float spawnTime = 1.0f;
};