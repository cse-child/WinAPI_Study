#include "Framework.h"

Inventory::Inventory()
	:Panel(TEXTURE->Add(L"Textures/panel.bmp", 512, 512))
{
	pos = { CENTER_X + 300, CENTER_Y };

	Observer::Get()->AddObjEvent("Purchase", 
		bind(&Inventory::GetItem, this, placeholders::_1));

	Observer::Get()->AddObjEvent("Select", 
		bind(&Inventory::OnSelectItem, this, placeholders::_1));

	Observer::Get()->SetEvent("Sell", bind(&Inventory::SellItem, this));

	Load();
}

Inventory::~Inventory()
{
	Save();
}

void Inventory::Update()
{
	Drag();

	int colCount = 3;

	float interval = 10.0f;

	Vector2 offset(-150, -150);

	int count = 0;
	for (Item* item : items)
	{
		// 바둑판 형식으로 출력
		int x = count % colCount;
		int y = count / colCount;

		Vector2 temp;
		temp.x = offset.x + x * item->Size().x + x * interval;
		temp.y = offset.y + y * item->Size().y + y * interval;

		item->Pos() = temp + pos;

		item->Update();

		count++;
	}
}

void Inventory::Render(HDC hdc)
{
	Panel::Render(hdc);

	wstring str = L"GOLD : " + to_wstring(gold);
	TextOut(hdc, pos.x, pos.y + 220, str.c_str(), str.length());
}

void Inventory::GetItem(void* item)
{
	ItemData data = ((Item*)item)->GetData();

	if (gold < data.price)
	{
		MessageBox(hWnd, L"돈이 부족합니다.", L"경고", MB_OK);
		return;
	}

	gold -= data.price;

	items.push_back(new Item(data));
}

void Inventory::SellItem()
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i] == selectItem)
		{
			gold += selectItem->GetData().price * 0.5f;

			items.erase(items.begin() + i);
			return;
		}
	}
}

void Inventory::OnSelectItem(void* item)
{
	selectItem = (Item*)item;
}

void Inventory::Save()
{
	BinaryWriter* writer = new BinaryWriter("TextData/Inventory.data");

	writer->Int(gold);

	vector<int> itemKeys;

	for (Item* item : items)
	{
		itemKeys.push_back(item->GetData().key);
	}

	writer->UInt(itemKeys.size());

	// &itemKeys[0] == itemKeys.data() 첫번째 주소값
	// 배열은 이름이 첫번째 주소값이지만 벡터는 아님
	writer->Byte(itemKeys.data(), sizeof(int)*itemKeys.size());

	delete writer;
}

void Inventory::Load()
{
	BinaryReader* reader = new BinaryReader("TextData/Inventory.data");

	gold = reader->Int();

	UINT size = reader->UInt();
	
	vector<int> itemKeys(size);

	void* temp = itemKeys.data();

	reader->Byte(&temp, sizeof(int) * size);

	for (int key : itemKeys)
	{
		Item* item = new Item(DataManager::Get()->GetItemDatas()[key]);
		items.push_back(item);
	}

	delete reader;
}

