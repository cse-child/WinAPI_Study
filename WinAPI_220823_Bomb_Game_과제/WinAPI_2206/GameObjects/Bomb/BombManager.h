#pragma once

class BombManager : public Singleton<BombManager>
{
public:
	BombManager();
	~BombManager();

	void Update();
	void Render(HDC hdc);

	void PlantBomb(Vector2 pos);
	
	void CreateBombs(UINT poolingCount);

	void SetLandTexture(Texture* texture);

	Circle* GetExplodeCircle();

	bool IsPlant() { return isPlant; }

private:
	vector<Bomb*> bombs;

	HBRUSH hBrush;
	HPEN hPen;

	bool isPlant = false;
};