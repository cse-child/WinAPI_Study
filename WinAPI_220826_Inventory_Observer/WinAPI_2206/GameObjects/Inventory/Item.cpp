#include "Framework.h"

Item::Item(ItemData data)
	:data(data), Button(TEXTURE->Add(L"Textures/items.bmp", 320, 320, 10, 10))
{
	size = { 100, 100 };
	selectImage = new ImageRect(TEXTURE->Add(L"Textures/selected.bmp", 128, 128));
	selectImage->Size() = size;

	Observer::Get()->AddObjEvent("Select", bind(&Item::SelectItem, this, placeholders::_1));

	SetEvent(bind(&Item::ClickItem, this));
}

Item::~Item()
{
	delete selectImage;
}

void Item::Update()
{
	Button::Update();

	selectImage->Pos() = pos;
}

void Item::Render(HDC hdc)
{
	ImageRect::Render(hdc, data.imageFrame);

	if (isSelected)
		selectImage->Render(hdc);
}

void Item::SelectItem(void* item)
{
	isSelected = (item == this);
}

void Item::ClickItem()
{
	Observer::Get()->ExcuteEvents("Select", this);
}