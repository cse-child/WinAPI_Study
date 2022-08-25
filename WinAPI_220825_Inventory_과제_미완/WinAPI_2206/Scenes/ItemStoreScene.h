#pragma once

class ItemStoreScene : public Scene
{
public:
	ItemStoreScene();
	~ItemStoreScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	//void SelectItem(Item* item) { this->item = item; }
	//void BuyItem(void* obj);

private:
	void CreateButton();

private:
	Button* button;

	//Item* item;
};