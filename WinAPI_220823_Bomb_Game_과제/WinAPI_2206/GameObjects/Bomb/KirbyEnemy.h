#pragma once

class KirbyEnemy : public ImageRect
{
private:
	const float GRAVITY = 980.0f;

public:
	KirbyEnemy();
	~KirbyEnemy();

	void Update();
	void Render(HDC hdc);

	void Drop();

	void SetLandTexture(Texture* texture) { landTexture = texture; }
	void SetPlayerPos(Vector2 pos) { playerPos = pos; }

	bool CollisionExplodeCircle(Circle* circle);

private:
	void Move();
	void PlayerToMove();

private:
	float speed = 200.0f;
	float traceSpeed = 70.0f;

	Texture* landTexture;

	Vector2 playerPos;
	Vector2 velocity;
	Vector2 direction;

	bool isLand = false;
};