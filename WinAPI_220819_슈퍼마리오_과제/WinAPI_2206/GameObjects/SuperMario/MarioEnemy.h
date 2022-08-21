#pragma once

class MarioEnemy : public ImageRect
{
public:
	enum ActionType
	{
		WALK, DIE
	};

public:
	MarioEnemy();
	~MarioEnemy();

	void Update();
	void Render(HDC hdc);

	void SetAction(ActionType type);

private:
	void Move();

	void CreateAnimations();

	void EndDie();

private:
	map<ActionType, Animation*> animations;

	ActionType curType;

	bool isLeftMove;

	float speed = 100.0f;
};