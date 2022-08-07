#pragma once

class FollowManager : public Singleton<FollowManager>
{
private:
	const UINT BRUSH_NUM = 10;

public:
	FollowManager();
	~FollowManager();

	void Update();
	void Render(HDC hdc);

	void Follow();

	void CreateCircles(UINT poolingCount);

	bool IsCollision(Circle* circle);

	void SetPlayerPos(Vector2 playerPos) { this->playerPos = playerPos; }
	Vector2 GetPlayerPos() { return playerPos; }

private:
	vector<FollowCircle*> circles;

	vector<HBRUSH> brushes;

	float playTime = 0.0f;
	float spawnTime = 70.0f;

	Vector2 playerPos = {0,0};
};