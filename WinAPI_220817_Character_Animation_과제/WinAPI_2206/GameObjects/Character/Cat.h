#pragma once

class Cat : public ImageRect
{
private:
	enum ActionType
	{
		IDLE, WALK, JUMP, KICK, MAX
	};

	const float JUMP_POWER = 500.0f;
	const float GRAVITY = 1245.0f;

public:
	Cat();
	~Cat();

	void Update();
	void Render(HDC hdc);

private:
	void Init();
	void Idle();
	void Move();
	void Jump();
	void Kick();
	void CreateAnimation();

private:
	Texture* idleTexture;
	Texture* walkTexture;
	Texture* jumpTexture;
	Texture* kickTexture;

	map<ActionType, Animation*> animations;

	ActionType curType;

	float speed = 300.0f;
	float jumpVelocity = 0.0f;

	bool isMove;
	bool isJump;
	bool isKick;
};