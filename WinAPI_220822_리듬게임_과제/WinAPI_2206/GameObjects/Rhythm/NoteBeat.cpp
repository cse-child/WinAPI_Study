#include "Framework.h"

NoteBeat::NoteBeat()
{
	Texture* texture = TEXTURE->Add(L"Textures/ArrowDirection.bmp", 1613, 761, 4, 2);
	SetTexture(texture);

	isActive = false;

	size *= 0.3f;
}

NoteBeat::~NoteBeat()
{
}

void NoteBeat::Update()
{
	if (!isActive) return;

	pos.y += speed * DELTA;

	if (Top() > WIN_HEIGHT)
		isActive = false;
}

void NoteBeat::Render(HDC hdc)
{
	if (!isActive) return;

	ImageRect::Render(hdc, { (int)beatType, 0 });
}

void NoteBeat::Init()
{
	UINT type = Random(0, BEAT_COUNT);
	beatType = (BeatType)type;

	pos.x = WIN_WIDTH * 0.35f + size.x * beatType;
	pos.y = 0;

	isActive = true;
}
