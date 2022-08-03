#include "Framework.h"

ObjectManager::ObjectManager()
{
	CreateBrush();
}

ObjectManager::~ObjectManager()
{
	for (Object* object : objects)
		delete object;

	for (HBRUSH& brush : brushes)
		DeleteObject(brush);

}

void ObjectManager::Update()
{
	playTime++;
	totalPlayTime++;

	if (playTime > spawnTime)
	{
		Fall();
		playTime = 0;
		spawnTime = Random((int)MIN_SPAWN_TIME, MAX_SPAWN_TIME);
	}

	for (Object* object : objects)
		object->Update();
}

void ObjectManager::Render(HDC hdc)
{
	for (Object* object : objects)
		object->Render(hdc);

	wstring str = L"Catch Count : " + to_wstring(count);
	TextOut(hdc, 0, 0, str.c_str(), str.length());

	str = L"Total Play Time : " + to_wstring(totalPlayTime);
	TextOut(hdc, 0, 20, str.c_str(), str.length());
}

void ObjectManager::CreateObject(UINT poolingSize)
{
	objects.resize(poolingSize);

	for (Object*& object : objects)
	{
		randomType = Random(0, MAX);
		//randomType = 0;
		POINT randomPos = { Random(0, WIN_WIDTH), 0 };

		switch (randomType)
		{
		case ObjectManager::CIRCLE:
			object = new Circle(randomPos,Random((int)MIN_OBJECT_SIZE, MAX_OBJECT_SIZE));
			break;
		case ObjectManager::RECT:
			object = new Rect(randomPos, Random((int)MIN_OBJECT_SIZE, MAX_OBJECT_SIZE));
			break;
		}
		object->SetBrush(brushes[Random(0, brushes.size())]);
		object->SetSpeed(Random(1, MAX_SPEED));
	}
}

void ObjectManager::CreateBrush()
{
	brushes.resize(BRUSH_COUNT);

	for (HBRUSH& brush : brushes)
	{
		UINT R = Random(0, 255);
		UINT G = Random(0, 255);
		UINT B = Random(0, 255);
		brush = CreateSolidBrush(RGB(R, G, B));
	}
}

void ObjectManager::IncreaseCount()
{
	count++;

	if (count >= GAME_END_COUNT)
	{
		GameManager::Get()->Stop();

		wstring str = L"Game Clear!\nPlay Time : " + to_wstring(totalPlayTime) + L" !";
		
		MessageBox(GameManager::Get()->GetHWND(),
			str.c_str(), L"Result", MB_OK);

		RestartGame();
	}
}

void ObjectManager::Fall()
{
	for (Object* object : objects)
	{
		if (!object->IsActive())
		{
			POINT randomPos = { Random(0, WIN_WIDTH), 0 };
			object->Fall(randomPos);
			object->SetBrush(brushes[Random(0, brushes.size())]);
			object->SetSpeed(Random(1, MAX_SPEED));
			return;
		}
	}
}

void ObjectManager::RestartGame()
{
	count = 0;
	totalPlayTime = 0;
	for (Object* object : objects)
	{
		POINT randomPos = { Random(0, WIN_WIDTH), 0 };
		object->Fall(randomPos);
		object->SetBrush(brushes[Random(0, brushes.size())]);
		object->SetSpeed(Random(1, MAX_SPEED));
	}
	GameManager::Get()->Play();
}
