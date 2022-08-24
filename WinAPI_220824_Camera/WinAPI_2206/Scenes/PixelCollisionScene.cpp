#include "Framework.h"
#include "PixelCollisionScene.h"

PixelCollisionScene::PixelCollisionScene()
{
	background = new ImageRect(TEXTURE->Add(L"Textures/BG.bmp", WIN_WIDTH, WIN_HEIGHT));
	background->Pos() = { CENTER_X, CENTER_Y };

	mountain = new ImageRect(TEXTURE->Add(L"Textures/mountain.bmp", WIN_WIDTH, WIN_HEIGHT));
	mountain->Pos() = { CENTER_X, CENTER_Y };

	cookie = new Cookie();
	cookie->SetLand(mountain->GetTexture());
}

PixelCollisionScene::~PixelCollisionScene()
{
	delete background;
	delete mountain;

	delete cookie;
}

void PixelCollisionScene::Update()
{
	cookie->Update();
}

void PixelCollisionScene::Render(HDC hdc)
{
	background->Render(hdc);
	mountain->Render(hdc);

	cookie->Render(hdc);
}
