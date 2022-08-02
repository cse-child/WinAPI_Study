#pragma once

class SpawnCircle : public Circle
{
private:
	const UINT MIN_LIFE_TIME = 100;
	const UINT MAX_LIFE_TIME = 300;

	const UINT MIN_RADIUS = 10;
	const UINT MAX_RADIUS = 500;

public:
	SpawnCircle();
	SpawnCircle(POINT pos, UINT radius);
	~SpawnCircle();

	void Update();
	void Render(HDC hdc);

	void Spawn();

	bool& Active() { return isActive; }

	void SetBrush(HBRUSH brush) { this->brush = brush;  }

private:
	bool isActive = false;

	UINT lifeTime = 0;
	UINT safeTime = 0;

	HBRUSH brush;
};