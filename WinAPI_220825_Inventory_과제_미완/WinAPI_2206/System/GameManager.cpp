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
#include "Scenes/RunningScene.h"
#include "Scenes/EffectScene.h"
#include "Scenes/PixelCollisionScene.h"
#include "Scenes/CameraScene.h"
#include "Scenes/StartScene.h"
#include "Scenes/ItemStoreScene.h"

GameManager::GameManager()
{
    Create();

    SCENE->Add("FlappyBird", new FlappyBirdScene());
    SCENE->Add("Camera", new CameraScene());
    SCENE->Add("Start", new StartScene());
    SCENE->Add("ItemStore", new ItemStoreScene());

    SCENE->ChangeScene("ItemStore");
}

GameManager::~GameManager()
{
    Delete();
}

void GameManager::Update()
{
    if (isStop) return;

    if (KEY_DOWN(VK_F1))
        Texture::SwichDebug();

    Keyboard::Get()->Update();
    Timer::Get()->Update();
    EffectManager::Get()->Update();
    Audio::Get()->Update();
    Camera::Get()->Update();

    SCENE->Update();
}

void GameManager::Render()
{
    PatBlt(backBuffer, 0, 0, WIN_WIDTH, WIN_HEIGHT, WHITENESS);

    SCENE->Render(backBuffer);
    EffectManager::Get()->Render(backBuffer);
    
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

    // 뒷배경 투명 모드
    SetBkMode(backBuffer, TRANSPARENT);
}

void GameManager::Create()
{
    Keyboard::Get();
    Timer::Get();
    TextureManager::Get();
    EffectManager::Get();
    Audio::Get();
    Camera::Get();
    SceneManager::Get();
}

void GameManager::Delete()
{
    Keyboard::Delete();
    Timer::Delete();
    TextureManager::Delete();
    EffectManager::Delete();
    Audio::Delete();
    Camera::Delete();
    SceneManager::Delete();
}
