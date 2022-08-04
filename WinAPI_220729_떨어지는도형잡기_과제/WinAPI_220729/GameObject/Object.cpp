#include "Framework.h"

Object::Object()
{
	isActive = false;
	pos = { (int)CENTER_X, (int)CENTER_Y };
}

Object::~Object()
{
}

void Object::Update()
{
	if (!isActive)
		return;

	if (GetAsyncKeyState(VK_LBUTTON))
	{
		if (IsCollision(mousePos))
		{
			isActive = false;
			ObjectManager::Get()->IncreaseCount();
		}
	}

	pos.y += speed;

	if (pos.y > WIN_HEIGHT)
	{
		isActive = false;
	}
}

void Object::Fall(POINT pos)
{
	isActive = true;
	this->pos = pos;
}
