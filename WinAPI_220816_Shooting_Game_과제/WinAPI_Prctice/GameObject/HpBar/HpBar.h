#pragma once

class HpBar : public Rect
{
public:
	HpBar(Vector2 pos, Vector2 size, int maxHp=100, int minHp=0);
	~HpBar();

	void Update();
	void Render(HDC hdc);

	void DecreaseHP(int hp) { curHp -= hp; }
	void IncreaseHP(int hp) { curHp += hp; }
	int GetHP() { return curHp; }

	void Init();

private:
	HBRUSH backBrush;
	HBRUSH frontBrush;

	int maxHp;
	int minHp;
	int curHp;


};