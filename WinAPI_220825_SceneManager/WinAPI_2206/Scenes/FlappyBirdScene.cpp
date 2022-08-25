#include "Framework.h"
#include "FlappyBirdScene.h"

FlappyBirdScene::FlappyBirdScene()
{
}

FlappyBirdScene::~FlappyBirdScene()
{
}

void FlappyBirdScene::Update()
{
    landscape->Update();
    plane->Update();

    PipeManager::Get()->Update();

    if (PipeManager::Get()->IsCollision(plane))
    {
        MessageBox(hWnd, L"GameOver", L"GameOver", MB_OK);        
        SCENE->ChangeScene("Camera");
    }
}

void FlappyBirdScene::Render(HDC hdc)
{
    landscape->Render(hdc);
    plane->Render(hdc);

    PipeManager::Get()->Render(hdc);
}

void FlappyBirdScene::Start()
{
    landscape = new Landscape();
    plane = new Plane();

    PipeManager::Get();
}

void FlappyBirdScene::End()
{
    delete landscape;
    delete plane;

    PipeManager::Delete();
}
