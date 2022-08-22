#include "Framework.h"
#include "RhythmGameScene.h"


RhythmGameScene::RhythmGameScene()
{
	Audio::Get()->Add("bgm", "Sounds/lofi_bgm.ogg", true);
	Audio::Get()->Add("beat", "Sounds/beat.wav");

	Audio::Get()->Play("bgm");

	Texture* texture = TEXTURE->Add(L"Textures/LineEffect.bmp", 780, 240, 3, 6);
	EffectManager::Get()->Add("line", texture, 15, 0.01f);

	BaseBeatManager::Get();
	NoteBeatManager::Get()->CreateNoteBeats(10);
}

RhythmGameScene::~RhythmGameScene()
{
	BaseBeatManager::Delete();
	NoteBeatManager::Delete();
}

void RhythmGameScene::Update()
{
	BaseBeatManager::Get()->Update();
	NoteBeatManager::Get()->Update();

	Effect();
	CollisionBeat();

	curType = NoteBeat::NONE;
}

void RhythmGameScene::Render(HDC hdc)
{
	BaseBeatManager::Get()->Render(hdc);
	NoteBeatManager::Get()->Render(hdc);

	wstring str = L"Score : " + to_wstring(score);
	TextOut(hdc, CENTER_X, WIN_HEIGHT - 30, str.c_str(), str.length());
}

void RhythmGameScene::CollisionBeat()
{
	for (NoteBeat* beat : NoteBeatManager::Get()->GetBeats())
	{
		if (!beat->Active()) return;
		if (curType == NoteBeat::NONE) return;

		if (BaseBeatManager::Get()->IsCollision(beat, curType))
		{
			beat->Active() = false;
			score += 100;

			Audio::Get()->Play("beat");

			return;
		}
	}
}

void RhythmGameScene::Effect()
{
	if (KEY_DOWN(VK_UP))
	{
		EffectManager::Get()->Play("line",
			BaseBeatManager::Get()->GetPos(NoteBeat::UP) + effectOffset);
		curType = NoteBeat::UP;
	}
	if (KEY_DOWN(VK_DOWN))
	{
		EffectManager::Get()->Play("line",
			BaseBeatManager::Get()->GetPos(NoteBeat::DOWN) + effectOffset);
		curType = NoteBeat::DOWN;
	}
	if (KEY_DOWN(VK_LEFT))
	{
		EffectManager::Get()->Play("line",
			BaseBeatManager::Get()->GetPos(NoteBeat::LEFT) + effectOffset);
		curType = NoteBeat::LEFT;
	}
	if (KEY_DOWN(VK_RIGHT))
	{
		EffectManager::Get()->Play("line",
			BaseBeatManager::Get()->GetPos(NoteBeat::RIGHT) + effectOffset);
		curType = NoteBeat::RIGHT;
	}
}
