#pragma once

class Item : public Button
{
public:
	Item(ItemData data);
	~Item();

	void Update();
	void Render(HDC hdc);

	void SetSelected(bool selected) { isSelected = selected; }

	ItemData GetData() { return data; }

	Vector2& LocalPos() {return localPos;}

	void SelectItem(void* item);

	void ClickItem();

private:
	ItemData data;

	ImageRect* selectImage;

	bool isSelected = false;

	Vector2 localPos;

};