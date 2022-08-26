#include "Framework.h"

Store::Store()
	:ImageRect(TEXTURE->Add(L"Textures/panel.bmp", 512, 512))
{
	CreateItems();

	pos = { CENTER_X, CENTER_Y };

	Observer::Get()->AddObjEvent("Select", bind(&Store::OnSelectItem, this, placeholders::_1));
}

Store::~Store()
{
	for (Item* item : items)
		delete item;
	items.clear();
}

void Store::Update()
{
	for (Item* item : items)
	{
		item->Pos() = pos + item->LocalPos();
		item->Update();
	}
}

void Store::Render(HDC hdc)
{
	ImageRect::Render(hdc);

	for (Item* item : items)
		item->Render(hdc);

	ShowSelectItemInfo(hdc);
}

void Store::CreateItems()
{
	map<int, ItemData> itemDatas = DataManager::Get()->GetItemDatas();

	int colCount = 2;

	float interval = 10.0f;

	Vector2 offset(-150, -150);

	for (pair<int, ItemData> itemData : itemDatas)
	{
		Item* item = new Item(itemData.second);
		//item->SetObjEvent(bind(&Store::OnSelectItem, this, placeholders::_1));

		// 바둑판 형식으로 출력
		int x = items.size() % colCount;
		int y = items.size() / colCount;

		item->LocalPos().x = offset.x + x * item->Size().x + x * interval;
		item->LocalPos().y = offset.y + y * item->Size().y + y * interval;

		items.push_back(item);
	}
}

void Store::OnSelectItem(void* selectItem)
{
	this->selectItem = (Item*)selectItem;

	/*for (Item* item : items)
	{
		if (item == selectItem)
		{
			item->SetSelected(true);
			
		}
		else
		{
			item->SetSelected(false);
		}
	}*/
}

void Store::ShowSelectItemInfo(HDC hdc)
{
	if (selectItem == nullptr) return;

	ItemData data = selectItem->GetData();

	Vector2 offset = pos + Vector2(20, -150);
	TextOutA(hdc, offset.x, offset.y, data.name.c_str(), data.name.length());

	string temp = "Power : " + to_string(data.value);
	TextOutA(hdc, offset.x, offset.y + 20, temp.c_str(), temp.length());

	temp = "Price : " + to_string(data.price);
	TextOutA(hdc, offset.x, offset.y + 40, temp.c_str(), temp.length());

}
