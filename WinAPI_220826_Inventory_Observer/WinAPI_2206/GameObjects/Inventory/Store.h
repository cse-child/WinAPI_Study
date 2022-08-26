#pragma once

class Store : public ImageRect
{
public:
	Store();
	~Store();

	void Update();
	void Render(HDC hdc);

private:
	void CreateItems();

	void OnSelectItem(void* selectItem);

	void ShowSelectItemInfo(HDC hdc);

private:
	vector<Item*> items;

	Item* selectItem = nullptr;
};