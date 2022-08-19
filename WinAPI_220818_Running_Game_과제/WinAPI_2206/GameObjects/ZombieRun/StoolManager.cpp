#include "Framework.h"

StoolManager::StoolManager()
{
	texture = TEXTURE->Add(L"Textures/Stool.bmp", 258, 104);

	CreateStools();
}

StoolManager::~StoolManager()
{
	for (ImageRect* stool : stools)
		delete stool;
	
	stools.clear();
}

void StoolManager::Update()
{
	for (int i = 0; i < STOOL_NUM; i++)
	{
		stools[i]->Pos().x -= speed * DELTA;

		if (stools[i]->Right() <= 0)
		{
			if (i == 0 && !isStart)
			{
				stools[0]->Size() = texture->GetSize();
				isStart = true;
			}
			int lastStoolIndex = (i - 1 < 0) ? stools.size() - 1 : i - 1;
			stools[i]->Pos().x = stools[lastStoolIndex]->Right() + Random(MIN_STOOL_WIDTH, MAX_STOOL_WIDTH);
			stools[i]->Pos().y = Random(MIN_STOOL_HEIGHT, MAX_STOOL_HEIGHT);
		}
	}
}

void StoolManager::Render(HDC hdc)
{
	for (UINT i = 0; i < STOOL_NUM; i++)
	{
		stools[i]->Render(hdc);
	}
}

ImageRect* StoolManager::IsCollision(Rect* rect)
{
	for (ImageRect* stool : stools)
	{
		if (stool->IsCollision(rect))
			return stool;
	}
	return nullptr;
}

void StoolManager::CreateStools()
{
	stools.resize(STOOL_NUM);

	stools[0] = new ImageRect(texture);
	stools[0]->Size().x *= 5.0f;
	stools[0]->Pos().x = stools[0]->Size().x / 2.0f;
	stools[0]->Pos().y = STOOL_HEIGHT;

	for (UINT i = 1; i < STOOL_NUM; i++)
	{
		stools[i] = new ImageRect(texture);
		stools[i]->Pos().x = stools[i - 1]->Right() + stools[i]->Size().x + Random(MIN_STOOL_WIDTH, MAX_STOOL_WIDTH);
		//stools[i]->Pos().y = STOOL_HEIGHT;
		stools[i]->Pos().y = Random(MIN_STOOL_HEIGHT, MAX_STOOL_HEIGHT);
	}
}

