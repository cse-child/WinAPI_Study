#include "Framework.h"

NoteBeatManager::NoteBeatManager()
{
}

NoteBeatManager::~NoteBeatManager()
{
	for (NoteBeat* beat : beats)
		delete beat;
	beats.clear();
}

void NoteBeatManager::Update()
{
	playTime += DELTA;

	if (playTime > spawnTime)
	{
		Spawn();
		playTime = 0.0f;
	}

	for (NoteBeat* beat : beats)
		beat->Update();
}

void NoteBeatManager::Render(HDC hdc)
{
	for (NoteBeat* beat : beats)
		beat->Render(hdc);
}

void NoteBeatManager::CreateNoteBeats(UINT poolingCount)
{
	beats.resize(poolingCount);

	for (NoteBeat*& beat : beats)
	{
		beat = new NoteBeat();
	}
}

void NoteBeatManager::Spawn()
{
	for (NoteBeat* beat : beats)
	{
		if (!beat->Active())
		{
			beat->Init();
			return;
		}
	}
}