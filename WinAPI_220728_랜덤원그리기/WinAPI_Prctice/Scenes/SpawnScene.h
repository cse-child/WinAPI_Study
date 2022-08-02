#pragma once

class SpawnScene : public Scene
{
private:
	const UINT SPAWN_SIZE = 100;
	const UINT BRUSH_SIZE = 20;

public:
	SpawnScene();
	~SpawnScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	void Spawn();
	void CreateBrushes();

private:
	vector<SpawnCircle*> circles;

	//SpawnCircle* circle;

	UINT spawnTime = 0;
	UINT playTime = 0;

	vector<HBRUSH> brushes;
};