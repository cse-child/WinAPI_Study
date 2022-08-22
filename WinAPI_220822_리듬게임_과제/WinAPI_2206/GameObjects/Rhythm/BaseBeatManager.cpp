#include "Framework.h"

BaseBeatManager::BaseBeatManager()
{
	Texture* texture = TEXTURE->Add(L"Textures/ArrowDirection.bmp", 1613, 761, 4, 2);
	
	beats.resize(BEAT_COUNT);

	for (UINT i = 0; i < BEAT_COUNT; i++)
	{
		beats[i] = new ImageRect(texture);
		beats[i]->Size() *= 0.3f;
		beats[i]->Pos().x = WIN_WIDTH * 0.35f + beats[i]->Size().x * i;
		beats[i]->Pos().y = WIN_HEIGHT - 100.0f;
	}

}

BaseBeatManager::~BaseBeatManager()
{
	for (ImageRect* beat : beats)
		delete beat;
	beats.clear();
}

void BaseBeatManager::Update()
{

}

void BaseBeatManager::Render(HDC hdc)
{
	for (UINT i = 0; i < BEAT_COUNT; i++)
	{
		beats[i]->Render(hdc, { (int)i, 1 });
	}
	//beats->Render(hdc, {0, 1});
}

bool BaseBeatManager::IsCollision(Rect* rect, NoteBeat::BeatType type)
{
	return beats[type]->IsCollision(rect);
}
