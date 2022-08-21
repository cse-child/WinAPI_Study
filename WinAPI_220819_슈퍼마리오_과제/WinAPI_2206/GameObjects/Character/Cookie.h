#pragma once

class Cookie : public ImageRect
{
private:
	const float JUMP_POWER = 700.0f;
	const float GRAVITY = 980.0f;
	const float MAX_VELOCITY = 500.0f;
	const float ACCEL = 700.0f; // 가속
	const float DECEL = 2.0f; // 감속

	const UINT MAX_JUMP_COUNT = 2;

	enum ActionType
	{
		IDLE,
		RUN_R, JUMP_UP_R, JUMP_DOWN_R, ROLL_R,
		RUN_L, JUMP_UP_L, JUMP_DOWN_L, ROLL_L
	};

public:
	Cookie();
	~Cookie();

	void Update();
	void Render(HDC hdc);

private:
	void Move();
	void Jump();
	void SetAnimation();

	void EndRoll();

	void CollisionLand();

	void SetAction(ActionType type);

	void CreateAnimations();

private:
	map<ActionType, Animation*> animations;

	ActionType curType = IDLE;

	float speed = 300.0f;
	

	UINT jumpCount = 0;

	Vector2 velocity; // 중력

	bool isRight = true;

	Rect* bodyRect;
	Vector2 bodyOffset; // 고정값
};