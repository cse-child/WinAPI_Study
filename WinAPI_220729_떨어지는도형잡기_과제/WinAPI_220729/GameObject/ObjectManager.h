#pragma once

class ObjectManager : public Singleton<ObjectManager>
{
private:
	enum ObjectType
	{
		CIRCLE, RECT, MAX
	};

	const UINT MIN_SPAWN_TIME = 0;
	const UINT MAX_SPAWN_TIME = 30;
	const UINT MIN_OBJECT_SIZE = 10;
	const UINT MAX_OBJECT_SIZE = 50;
	const UINT MAX_SPEED = 8;
	const UINT BRUSH_COUNT = 10;
	const UINT GAME_END_COUNT = 10;

public:
	ObjectManager();
	~ObjectManager();

	void Update();
	void Render(HDC hdc);

	void CreateObject(UINT poolingSize);
	void CreateBrush();

	void IncreaseCount();

	void Fall();

	void RestartGame();

private:
	vector<Object*> objects;

	vector<HBRUSH> brushes;

	int count = 0;
	UINT randomType = 0;

	UINT spawnTime = 0;
	UINT playTime = 0;
	UINT totalPlayTime = 0;
	
};