#pragma once

class Bomb : public ImageRect
{
private:
	const float GRAVITY = 980.0f;

public:
	Bomb(HBRUSH brush, HPEN pen);
	~Bomb();

	void Update();
	void Render(HDC hdc);

	void PlantBomb();

	void SetLandTexture(Texture* texture) { landTexture = texture; }

	Vector2 GetExplodeSize();
	Circle* GetExplodeCircle();

private:
	void Move();

	void BombExplode();

	void DeleteLand();

private:
	float playTime;
	float bombTime;
	float bombUpSize = 1.0f;

	bool isPlant;

	Texture* landTexture;

	Vector2 velocity;

	HBRUSH hBrush;
	HPEN hPen;
};