#pragma once

class ZzangGu : public ImageRect
{
private:
	const float JUMP_POWER = 650.0f;
	const float GRAVITY = 1500.0f;
	const float MAX_VELOCITY = 500.0f;
	const float ACCEL = 700.0f;
	const float DECEL = 3.0f;
	const float SLOPE = 10.0f;
	const UINT MAX_JUMP_COUNT = 2;

	enum ActionType
	{
		IDLE_R, IDLE_L,
		WALK_R, WALK_L,
		JUMP_R, JUMP_L
	};
public:
	ZzangGu();
	~ZzangGu();

	void Update();
	void Render(HDC hdc);

	void SetLand(Texture* texture) { landTexture = texture; }

private:
	bool CanMove();

	void Move();
	void Jump();

	void SetAnimation();
	void SetAction(ActionType type);

	void CreateAnimations();

private:
	map<ActionType, Animation*> animations;

	ActionType curType;

	Vector2 velocity; 

	Texture* landTexture;

	UINT jumpCount = 0;

	float speed = 250.0f;
	float height = 0.0f;

	bool isRight = true;
};