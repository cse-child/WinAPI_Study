#pragma once

class Enemy : public ImageRect
{
public:
	Enemy();
	~Enemy();

	void Update();

	void Init();

private:
	void Move();

private:
	float speed = 300.0f;
};