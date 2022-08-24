#pragma once

class Rect;

class Camera : public Singleton<Camera>
{
public:
	Camera();
	~Camera();

	void Update();
	
	Vector2 GetPos();
	void SetMapRect(Rect* rect) { mapRect = rect; }
	void SetTartget(Rect* rect) { target = rect; }
	void SetOffset(float x, float y) { offset = { x, y }; }

private:
	void FreeMode();
	void FollowMode();

	void FixPos(Vector2& pos);

private:
	Rect* rect;
	float moveSpeed = 800.0f;
	float followSpeed = 3.0f;

	Rect* mapRect = nullptr;
	Rect* target = nullptr;

	Vector2 offset = Vector2(CENTER_X, CENTER_Y);
	Vector2 destPos; // 목적지 위치
};