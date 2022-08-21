#include "Framework.h"
#include "FlappyBirdScene.h"

FlappyBirdScene::FlappyBirdScene()
{
    landscape = new Landscape();
    plane = new Plane();

    PipeManager::Get();
}

FlappyBirdScene::~FlappyBirdScene()
{
    delete landscape;
    delete plane;

    PipeManager::Delete();
}

void FlappyBirdScene::Update()
{
    landscape->Update();
    plane->Update();

    PipeManager::Get()->Update();

    if (PipeManager::Get()->IsCollision(plane))
    {
        MessageBox(hWnd, L"GameOver", L"GameOver", MB_OK);        
    }
}

void FlappyBirdScene::Render(HDC hdc)
{
    landscape->Render(hdc);
    plane->Render(hdc);

    PipeManager::Get()->Render(hdc);
}
