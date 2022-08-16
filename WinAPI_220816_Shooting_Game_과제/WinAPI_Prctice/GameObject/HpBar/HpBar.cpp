#include "Framework.h"
#include "HpBar.h"

HpBar::HpBar(Vector2 pos, Vector2 size, int maxHp, int minHp)
	:Rect(pos, size), maxHp(maxHp), minHp(minHp), curHp(maxHp)
{
	backBrush = CreateSolidBrush(RED);
	frontBrush = CreateSolidBrush(YELLOW);
}

HpBar::~HpBar()
{
	DeleteObject(backBrush);
	DeleteObject(frontBrush);
}

void HpBar::Update()
{
}

void HpBar::Render(HDC hdc)
{
	//wstring str = L"curHp = " + to_wstring(curHp);
	//TextOut(hdc, 0, 60, str.c_str(), str.length());
	//str = L"maxHp = " + to_wstring(maxHp);
	//TextOut(hdc, 0, 80, str.c_str(), str.length());
	//str = L"cur/max = " + to_wstring((curHp / maxHp));
	//TextOut(hdc, 0, 100, str.c_str(), str.length());

	SelectObject(hdc, backBrush);
	Rectangle(hdc, Left(), Top(), Right(), Bottom());

	SelectObject(hdc, frontBrush);
	Rectangle(hdc, Left(), Top(), Left() + (((float)curHp / maxHp) * size.x), Bottom());
}
