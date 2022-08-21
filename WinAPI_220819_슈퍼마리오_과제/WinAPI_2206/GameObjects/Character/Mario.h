#pragma once

class Mario : public ImageRect
{
public:
	enum ActionType
	{
		IDLE_R, IDLE_L,
		RUN_R, RUN_L,
		JUMP_R, JUMP_L,
		DIE
	};

private:
	const float JUMP_POWER = 700.0f;
	const float GRAVITY = 980.0f;
	const float MAX_VELOCITY = 500.0f;
	const float ACCEL = 700.0f;
	const float DECEL = 3.0f;
	const UINT MAX_JUMP_COUNT = 1;

public:
	Mario();
	~Mario();

	void Update();
	void Render(HDC hdc);

	void Attack();
	void Die();
	void SetDie();

	void SetAction(ActionType type);

	Rect* GetBodyRect() { return bodyRect; }

private:
	void Move();
	void Jump();

	void SetAnimation();

	void CollisionBlock();
	void CollisionJumpBlock();
	
	void CreateAnimations();


private:
	map<ActionType, Animation*> animations;

	ActionType curType;

	UINT jumpCount;

	Rect* bodyRect;

	Vector2 bodyOffset;
	Vector2 velocity;

	float speed;

	bool isRight;
	bool isDie;

};