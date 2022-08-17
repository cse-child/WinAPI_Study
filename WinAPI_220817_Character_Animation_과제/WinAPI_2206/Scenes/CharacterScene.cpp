#include "Framework.h"
#include "CharacterScene.h"

CharacterScene::CharacterScene()
{
	character = new Cat();
}

CharacterScene::~CharacterScene()
{
	delete character;
}

void CharacterScene::Update()
{
	character->Update();
}

void CharacterScene::Render(HDC hdc)
{
	character->Render(hdc);
}
