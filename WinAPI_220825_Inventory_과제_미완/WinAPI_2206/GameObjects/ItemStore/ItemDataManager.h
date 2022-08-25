#pragma once
//#include "Scenes/ItemStoreScene.h"

class ItemDataManager : public Singleton<ItemDataManager>
{
private:
	struct ItemData
	{
		int key;
		string name;
		string textureFilePath;
		int widthSize;
		int heightSize;
		int frame;
		int price;
		string stat;
	};

	const UINT COLUMN_NUM = 8;

public:
	ItemDataManager();
	~ItemDataManager();

	void Update();
	void Render(HDC hdc);

	//void SetItemStoreScene(ItemStoreScene* scene) { this->scene = scene; }
	//ItemStoreScene* GetItemStoreScene() { return scene; }

private:
	void LoadItemData();
	void CreateItems();

private:
	vector<ItemData> itemDatas;

	map<int, Item*> items;

	Texture* texture;

	//ItemStoreScene* scene;
};