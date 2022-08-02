#include "Framework.h"
#include "SpawnScene.h"

SpawnScene::SpawnScene()
{
	//circle = new SpawnCircle();

	circles.resize(SPAWN_SIZE);

	for (UINT i = 0; i < SPAWN_SIZE; i++)
	{
		//circles.push_back(new SpawnCircle());
		circles[i] = new SpawnCircle();
	}

	CreateBrushes();
}

SpawnScene::~SpawnScene()
{
	//delete circle;

	for (SpawnCircle* circle : circles)
		delete circle;

	for (HBRUSH brush : brushes)
		DeleteObject(brush);
}

void SpawnScene::Update()
{
	//if (GetAsyncKeyState(VK_LBUTTON))
	//	circle->Spawn();
	//
	//circle->Update();

	playTime++;

	if (playTime > spawnTime)
	{
		Spawn();
		playTime = 0;
		spawnTime = Random(50, 200);
	}

	for (SpawnCircle* circle : circles)
		circle->Update();
}

void SpawnScene::Render(HDC hdc)
{
	//circle->Render(hdc);

	for (SpawnCircle* circle : circles)
		circle->Render(hdc);
}

void SpawnScene::Spawn()
{
	for (SpawnCircle* circle : circles)
	{
		if (!circle->Active())
		{
			circle->Spawn();
			circle->SetBrush(brushes[Random(0, brushes.size())]);
			return;
		}
			
	}
}

void SpawnScene::CreateBrushes()
{
	brushes.resize(BRUSH_SIZE);

	for (HBRUSH& brush : brushes)
	{
		UINT r = Random(0, 255);
		UINT g = Random(0, 255);
		UINT b = Random(0, 255);
		brush = CreateSolidBrush(RGB(r,g,b));
	}
}
