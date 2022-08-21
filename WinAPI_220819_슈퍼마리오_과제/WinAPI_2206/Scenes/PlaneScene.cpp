#include "Framework.h"
#include "PlaneScene.h"

PlaneScene::PlaneScene()
{
    plane = new Plane();
    BulletManager::Get()->CreateBullets(50);
}

PlaneScene::~PlaneScene()
{
    delete plane;
    BulletManager::Delete();
}

void PlaneScene::Update()
{
    plane->Update();

    BulletManager::Get()->Update();
}

void PlaneScene::Render(HDC hdc)
{
    plane->Render(hdc);

    BulletManager::Get()->Render(hdc);
}
