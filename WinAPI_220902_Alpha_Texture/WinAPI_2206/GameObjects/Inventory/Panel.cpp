#include "Framework.h"

Panel::Panel(Texture* texture)
	:ImageRect(texture)
{
}

Panel::~Panel()
{
	for (Item* item : items)
		delete item;
	items.clear();
}

void Panel::Render(HDC hdc)
{
	ImageRect::Render(hdc);

	for (Item* item : items)
		item->Render(hdc);
}

void Panel::Drag()
{
	if (IsButtonOver()) return;

	if (KEY_DOWN(VK_LBUTTON))
	{
		if (IsCollision(mousePos))
		{
			isDrag = true;
			offset = pos - mousePos;
		}
	}

	if (isDrag && KEY_PRESS(VK_LBUTTON))
		pos = mousePos + offset;

	if (KEY_UP(VK_LBUTTON))
		isDrag = false;
}

bool Panel::IsButtonOver()
{
	for (Item* item : items)
	{
		if (item->IsCollision(mousePos))
			return true;
	}
	return false;
}