#pragma once

class Store : public Panel
{
public:
	Store();
	~Store();

	void Update();
	void Render(HDC hdc);

private:
	void CreateItems();

	void CreateButtons();

	void OnSelectItem(void* selectItem);

	void ShowSelectItemInfo(HDC hdc);

	void OnPurchase();
	void OnSell();

private:
	Item* selectItem = nullptr;

	Button* purchaseButton;
	Button* sellButton;
};