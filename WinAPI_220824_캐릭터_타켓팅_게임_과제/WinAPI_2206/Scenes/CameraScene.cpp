#include "Framework.h"
#include "CameraScene.h"

CameraScene::CameraScene()
{
	land = new ImageRect(TEXTURE->Add(L"Textures/GrassLand.bmp", 8720, 1700));
	land->Pos() += land->Half();

	cookie = new Cookie();
	cookie->SetLand(land->GetTexture());

	Camera::Get()->SetMapRect(land);
	Camera::Get()->SetTartget(cookie);
	//Camera::Get()->SetOffset(300, WIN_HEIGHT - 200);
}

CameraScene::~CameraScene()
{
	delete land;
	delete cookie;
}

void CameraScene::Update()
{
	cookie->Update();
}

void CameraScene::Render(HDC hdc)
{
	land->CamRender(hdc);
	cookie->Render(hdc);
}
