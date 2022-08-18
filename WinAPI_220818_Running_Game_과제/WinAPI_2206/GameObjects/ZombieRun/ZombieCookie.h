#pragma once

class ZombieCookie : public ImageRect
{
private:
	const float JUMP_POWER = 500.0f;
	const float GRAVITY = 980.0f;
	const UINT MAX_JUMP_COUNT = 2;

	enum ActionType
	{
		START, RUN, JUMP_UP, JUMP_DOWN, ROLL
	};

public:
	ZombieCookie();
	~ZombieCookie();

	void Update();
	void Render(HDC hdc);

	Rect* GetCollisionRect() { return collisionRect; }

	void SetLanding(); // ¹Ù´Ú¿¡ ÂøÁöÇßÀ»¶§

private:
	void Jump();
	void EndRoll();

	void SetAction(ActionType type);

	void CreateAnimations();

private:
	map<ActionType, Animation*> animations;

	ActionType curType;

	float speed = 300.0f;
	
	UINT jumpCount = 0;

	Vector2 velocity;

	Rect* collisionRect;
};