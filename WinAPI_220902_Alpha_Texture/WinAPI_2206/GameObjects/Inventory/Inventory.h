#pragma once

class Inventory : public Panel
{
public:
	Inventory();
	~Inventory();

	void Update();
	void Render(HDC hdc);

	void GetItem(void* item);
	void SellItem();

private:
	void OnSelectItem(void* item);

	void Save();
	void Load();

private:
	int gold = 100000;

	Item* selectItem;
};