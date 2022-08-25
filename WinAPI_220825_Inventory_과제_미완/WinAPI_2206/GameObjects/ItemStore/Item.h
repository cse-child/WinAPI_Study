#pragma once
//#include "Scenes/ItemStoreScene.h"

class Item : public ImageRect
{
private:
	struct DataStatus
	{
		string name;
		int frame;
		int price;
		string stat;
	};

public:
	Item(Texture* texture);
	~Item();

	void Update();
	void Render(HDC hdc);
	void RenderData(HDC hdc);

	void SetData(string name, int frame, int price, string stat);	

private:
	void BuyItem();

private:
	DataStatus data;

	HFONT font;
	HFONT titleFont;

	Button* button;
};