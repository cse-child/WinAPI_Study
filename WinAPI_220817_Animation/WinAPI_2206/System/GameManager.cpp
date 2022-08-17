#include "Framework.h"

//#include "Scenes/PlaneScene.h"
//#include "Scenes/DropScene.h"
//#include "Scenes/AngleScene.h"
//#include "Scenes/AvoidScene.h"
//#include "Scenes/CollisionScene.h"
//#include "Scenes/BreakoutScene.h"
//#include "Scenes/BitmapScene.h"
#include "Scenes/FlappyBirdScene.h"
#include "Scenes/ShootingScene.h"

GameManager::GameManager()
{
    Create();
    //scene = new PlaneScene();
    //scene = new DropScene();
    //scene = new AngleScene();
    //scene = new AvoidScene();
    //scene = new CollisionScene();
    //scene = new BreakoutScene();
    //scene = new BitmapScene();
    //scene = new FlappyBirdScene();
    scene = new ShootingScene();
}

GameManager::~GameManager()
{
    delete scene;

    Delete();
}

void GameManager::Update()
{
    if (isStop) return;

    if (KEY_DOWN(VK_F1))
        Texture::SwichDebug();

    Keyboard::Get()->Update();
    Timer::Get()->Update();

    scene->Update();
}

void GameManager::Render()
{
    PatBlt(backBuffer, 0, 0, WIN_WIDTH, WIN_HEIGHT, WHITENESS);

    scene->Render(backBuffer);
    
    Timer::Get()->Render(backBuffer);

    BitBlt(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT,
        backBuffer, 0, 0, SRCCOPY);
}

void GameManager::SetInit()
{
    hdc = GetDC(hWnd);

    backBuffer = CreateCompatibleDC(hdc);    
    bitmap = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);
    SelectObject(backBuffer, bitmap);
}

void GameManager::Create()
{
    Keyboard::Get();
    Timer::Get();
    TextureManager::Get();
}

void GameManager::Delete()
{
    Keyboard::Delete();
    Timer::Delete();
    TextureManager::Delete();
}
