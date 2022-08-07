#include "Framework.h"

FollowManager::FollowManager()
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

FollowManager::~FollowManager()
{
	for (FollowCircle* circle : circles)
		delete circle;

	circles.clear();

	for (HBRUSH brush : brushes)
		DeleteObject(brush);
}

void FollowManager::Update()
{
	playTime += 1.0f;

	if (playTime > spawnTime)
	{
		Follow ();
		playTime = 0.0f;
	}

	for (FollowCircle* circle : circles)
		circle->Update();
}

void FollowManager::Render(HDC hdc)
{
	for (FollowCircle* circle : circles)
		circle->Render(hdc);
}

void FollowManager::Follow()
{
	for (FollowCircle* circle : circles)
	{
		if (!circle->Active())
		{
			circle->SetBrush(brushes[Random(0, brushes.size())]);
			circle->InitCircle();
			return;
		}
	}
}

void FollowManager::CreateCircles(UINT poolingCount)
{
	circles.resize(poolingCount);

	for (FollowCircle*& circle : circles)
	{
		circle = new FollowCircle();
	}
}

bool FollowManager::IsCollision(Circle* circle)
{
	for (FollowCircle* followCircle : circles)
	{
		if (followCircle->IsCollision(circle))
		{
			followCircle->Active() = false;
			return true;
		}
	}
	return false;
}

