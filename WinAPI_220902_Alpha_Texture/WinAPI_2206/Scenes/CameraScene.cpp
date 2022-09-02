#include "Framework.h"
#include "CameraScene.h"

CameraScene::CameraScene()
{
	land = new ImageRect(TEXTURE->Add(L"Textures/GrassLand.bmp", 8720, 1700));
	land->Pos() += land->Half();
}

CameraScene::~CameraScene()
{
	delete land;
}

void CameraScene::Update()
{
	cookie->Update();
}

void CameraScene::LateUpdate()
{
	if (KEY_DOWN('1'))
		SCENE->ChangeScene("FlappyBird");
}

void CameraScene::Render(HDC hdc)
{
	land->CamRender(hdc);
	cookie->Render(hdc);
}

void CameraScene::Start()
{
	cookie = new Cookie();
	cookie->SetLand(land->GetTexture());

	Camera::Get()->SetMapRect(land);
	Camera::Get()->SetTartget(cookie);
	//Camera::Get()->SetOffset(300, WIN_HEIGHT - 200);
}

void CameraScene::End()
{
	delete cookie;
}
