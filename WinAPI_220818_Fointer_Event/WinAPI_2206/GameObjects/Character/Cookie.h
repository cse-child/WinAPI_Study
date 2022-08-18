#pragma once

class Cookie : public ImageRect
{
private:
	const float JUMP_POWER = 500.0f;
	const float GRAVITY = 980.0f;
	const UINT MAX_JUMP_COUNT = 2;

	enum ActionType
	{
		IDLE, RUN, JUMP_UP, JUMP_DOWN, ROLL
	};

public:
	Cookie();
	~Cookie();

	void Update();
	void Render(HDC hdc);

private:
	void Move();
	void Jump();

	void EndRoll();

	void SetAction(ActionType type);

	void CreateAnimations();

private:
	map<ActionType, Animation*> animations;

	ActionType curType = RUN;

	float speed = 300.0f;
	float accelation = 10.0f; // 가속도

	UINT jumpCount = 0;

	Vector2 velocity; // 중력
};