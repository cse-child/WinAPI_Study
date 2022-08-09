#include "Framework.h"
#include "AngleScene.h"

AngleScene::AngleScene()
{
	cannon = new Cannon();
}

AngleScene::~AngleScene()
{
	delete cannon;
}

void AngleScene::Update()
{
	cannon->Update();
}

void AngleScene::Render(HDC hdc)
{
	cannon->Render(hdc);
}
