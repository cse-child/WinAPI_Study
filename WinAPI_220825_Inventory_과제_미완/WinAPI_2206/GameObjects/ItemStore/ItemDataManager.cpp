#include "Framework.h"

ItemDataManager::ItemDataManager()
{
	LoadItemData();
	CreateItems();
}

ItemDataManager::~ItemDataManager()
{
	for (pair<int, Item*> item : items)
		delete item.second;
	items.clear();
}

void ItemDataManager::Update()
{
	for (pair<int, Item*> item : items)
		item.second->Update();
}

void ItemDataManager::Render(HDC hdc)
{
	for (int i = 1; i < itemDatas.size(); i++)
	{
		items[i]->Pos() = { CENTER_X * 0.1f, texture->GetSize().y * 4 * i};
		items[i]->Render(hdc);
	}
}

void ItemDataManager::LoadItemData()
{
	ifstream loadFile("DataTable/ItemTable.tsv", ios::in);

	bool isFirstLine = true;

	while (true)
	{
		string temp;

		if (isFirstLine)
		{
			for (UINT i = 0; i < COLUMN_NUM; i++) // COLUMN_NUM = 8
			{
				loadFile >> temp;
			}
			isFirstLine = false;
		}
			
		ItemData itemData;

		loadFile >> itemData.key >> itemData.name >> itemData.textureFilePath >> itemData.widthSize >>
			itemData.heightSize >> itemData.frame >> itemData.price >> itemData.stat;

		itemDatas.push_back(itemData);

		if (loadFile.eof())
			break;
	}
}

void ItemDataManager::CreateItems()
{
	for (ItemData data : itemDatas)
	{
		if (data.key == 0)
		{
			wstring temp;
			temp.assign(data.textureFilePath.begin(), data.textureFilePath.end());
			texture = TEXTURE->Add(temp, data.widthSize, data.heightSize, data.frame, data.frame);

			continue;
		}
		items[data.key] = new Item(texture);
		items[data.key]->SetData(data.name, data.frame, data.price, data.stat);
	}
}
