#include "Framework.h"

Item::Item(Texture* texture)
{
	SetTexture(texture);
	size *= 3;

	font = CreateFont(20, 0, 0, 0, 1, false, false, false, HANGUL_CHARSET, 100, 0, 0, 0, L"�ü�ü");
	titleFont = CreateFont(25, 0, 0, 0, 1, true, false, false, HANGUL_CHARSET, 100, 0, 0, 0, L"�ü�ü");
}

Item::~Item()
{
	
}

void Item::Update()
{
	BuyItem();
}

void Item::Render(HDC hdc)
{
	ImageRect::Render(hdc, { 0, data.frame });
	RenderData(hdc);
}

void Item::RenderData(HDC hdc)
{
	HFONT oldFont = (HFONT)SelectObject(hdc, titleFont);

	string info = data.name;
	TextOutA(hdc, pos.x + 100, pos.y - 40, info.c_str(), info.length());

	SelectObject(hdc, font);

	info = "���� : " + to_string(data.price) + "��";
	TextOutA(hdc, pos.x + 100, pos.y - 10, info.c_str(), info.length());

	info = "ȿ�� : " + data.stat;
	TextOutA(hdc, pos.x + 100, pos.y + 10, info.c_str(), info.length());

	SelectObject(hdc, oldFont);
}

void Item::SetData(string name, int frame, int price, string stat)
{
	data.name = name;
	data.frame = frame;
	data.price = price;
	data.stat = stat;
}

void Item::BuyItem()
{
	if (KEY_DOWN(VK_LBUTTON))
	{
		if (IsCollision(mousePos))
		{
			MessageBox(hWnd, L"Buy...................", L"Buying Item", MB_OK);
			//ItemDataManager::Get()->GetItemStoreScene()->SelectItem(this);
		}
	}
}
