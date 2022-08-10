#include "Framework.h"
#include "DropManager.h"

DropManager::DropManager()
{
	brushes.resize(BRUSH_NUM);

	for (HBRUSH& brush : brushes)
	{
		int r = Random(0, 255);
		int g = Random(0, 255);
		int b = Random(0, 255);

		brush = CreateSolidBrush(RGB(r, g, b));
	}
}

DropManager::~DropManager()
{
	for (DropCircle* circle : circles)
		delete circle;

	circles.clear();

	for (HBRUSH brush : brushes)
		DeleteObject(brush);
}

void DropManager::Update()
{
	playTime += 1.0f;

	if (playTime > spawnTime)
	{
		Drop();
		playTime = 0.0f;
	}
	for (DropCircle* circle : circles)
		circle->Update();
}

void DropManager::Render(HDC hdc)
{
	for (DropCircle* circle : circles)
		circle->Render(hdc);
}

void DropManager::Drop()
{
	for (DropCircle* circle : circles)
	{
		if (!circle->Active())
		{
			circle->SetBrush(brushes[Random(0, brushes.size())]);
			circle->InitCircle();
			return;
		}
	}
}

void DropManager::CreateCircles(UINT poolingCount)
{
	circles.resize(poolingCount);

	for (DropCircle*& circle : circles)
	{
		circle = new DropCircle();
	}
}

bool DropManager::IsCollision(Circle* circle)
{
	for (DropCircle* dropCircle : circles)
	{
		if (dropCircle->IsCollision(circle))
		{
			dropCircle->Active() = false;
			return true;
		}
	}
	return false;
}

void DropManager::Init()
{
	for (DropCircle* dropCircle : circles)
	{
		dropCircle->Active() = false;
	}
}

void DropManager::SetTarget(Circle* target)
{
	for (DropCircle* dropCircle : circles)
	{
		dropCircle->SetTarget(target);
	}
}
