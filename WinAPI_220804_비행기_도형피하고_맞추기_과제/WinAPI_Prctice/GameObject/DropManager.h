#pragma once
#include "DropCircle.h"

class DropManager : public Singleton<DropManager>
{
private:
	const UINT BRUSH_NUM = 20;
public:
	DropManager();
	~DropManager();

	void Update();
	void Render(HDC hdc);

	void Drop();

	void CreateCircles(UINT poolingCount);

	vector<DropCircle*> GetCircles() { return circles; }

private:
	vector<DropCircle*> circles;

	vector<HBRUSH> brushes;

	float playTime = 0.0f;
	float spawnTime = 30.0f;
};