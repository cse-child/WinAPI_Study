#include "Framework.h"
#include "EffectScene.h"

EffectScene::EffectScene()
{
	Texture* texture = TEXTURE->Add(L"Textures/Explosion.bmp", 512, 512, 4, 4);
	//effect = new Effect(texture);
	EffectManager::Get()->Add("exp", texture);

	FMOD::System_Create(&soundSystem);
	soundSystem->init(5, FMOD_INIT_NORMAL, nullptr);
	
	soundSystem->createSound("Sounds/bgm.ogg", FMOD_DEFAULT, nullptr, &sound);
	soundSystem->playSound(sound, nullptr, false, &channel);
	channel->setVolume(0.1f); // max: 1
}

EffectScene::~EffectScene()
{
	//delete effect;
}

void EffectScene::Update()
{
	if (KEY_DOWN(VK_LBUTTON))
		EffectManager:: Get()->Play("exp", mousePos);
		//effect->Play(mousePos);

	//effect->Update();
}

void EffectScene::Render(HDC hdc)
{
	//effect->Render(hdc);
}
