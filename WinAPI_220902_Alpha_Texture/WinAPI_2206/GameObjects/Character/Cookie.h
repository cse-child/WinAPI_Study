#pragma once

class Cookie : public ImageRect
{
private:
	const float JUMP_POWER = 700.0f;
	const float GRAVITY = 980.0f;
	const float MAX_VELOCITY = 500.0f;
	const float ACCEL = 700.0f; // 가속
	const float DECEL = 2.0f; // 감속
	const float SLOPE = 10.0f; // 기울기

	const UINT MAX_JUMP_COUNT = 2;

	enum ActionType
	{
		IDLE,
		RUN_R, JUMP_UP_R, JUMP_DOWN_R, ROLL_R,
		RUN_L, JUMP_UP_L, JUMP_DOWN_L, ROLL_L,
		ATTACK_R, ATTACK_L
	};

public:
	Cookie();
	~Cookie();

	void Update();
	void Render(HDC hdc);

	void SetLand(Texture* texture) { landTexture = texture; }

private:
	bool CanMove();

	void Move();
	void Jump();
	void SetAnimation();
	void Attack();

	void BombMove();

	void EndRoll();
	void EndAttack();

	void CollisionLand();

	void SetAction(ActionType type);

	void CreateAnimations();

private:
	map<ActionType, Animation*> animations;

	ActionType curType = IDLE;

	float speed = 300.0f;
	float height = 0.0f;
	

	UINT jumpCount = 0;

	Vector2 velocity; // 중력
	Vector2 bombVelocity = {200, 0};

	bool isRight = true;

	Rect* bodyRect;
	Vector2 bodyOffset; // 고정값

	Texture* landTexture;

	ImageRect* bomb;

	HBRUSH hBrush;
	HPEN hPen;
};