#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define CENTER_X (WIN_WIDTH * 0.5f)
#define CENTER_Y (WIN_HEIGHT * 0.5f)

#define PI 3.1415f

#define RED RGB(255, 0, 0)
#define GREEN RGB(0, 255, 0)
#define BLUE RGB(0, 0, 255)
#define YELLOW RGB(255, 255, 0)
#define CYAN RGB(0, 255, 255)
#define MAGENTA RGB(255, 0, 255)
#define BLACK RGB(0, 0, 0)
#define WHTIE RGB(255, 255, 255)

#define KEY_DOWN(k) Keyboard::Get()->Down(k)
#define KEY_UP(k) Keyboard::Get()->Up(k)
#define KEY_PRESS(k) Keyboard::Get()->Press(k)

#define DELTA Timer::Get()->GetTimeElapsed()

#define TEXTURE TextureManager::Get()

#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

//Framework Header
#include "Utilities/Singleton.h"
#include "Utilities/Keyboard.h"
#include "Utilities/Timer.h"

#include "Math/Vector2.h"
#include "Math/GameMath.h"

#include "Render/Texture.h"
#include "Render/TextureManager.h"
#include "Render/Animation.h"

using namespace GameMath;

//GameObject Header
#include "GameObjects/Basic/Circle.h"
#include "GameObjects/Basic/Line.h"
#include "GameObjects/Basic/Rect.h"
#include "GameObjects/Basic/ImageRect.h"

#include "GameObjects/UI/ProgressBar.h"

#include "GameObjects/Shooting/Bullet.h"
#include "GameObjects/Shooting/BulletManager.h"
//#include "GameObjects/Shooting/Plane.h"
#include "GameObjects/Shooting/DropCircle.h"
#include "GameObjects/Shooting/DropManager.h"
#include "GameObjects/Shooting/Enemy.h"
#include "GameObjects/Shooting/EnemyManager.h"

#include "GameObjects/Breakout/ControlBar.h"
#include "GameObjects/Breakout/Ball.h"
#include "GameObjects/Breakout/Brick.h"
#include "GameObjects/Breakout/BrickManager.h"

#include "GameObjects/FlappyBird/Landscape.h"
#include "GameObjects/FlappyBird/Plane.h"
#include "GameObjects/FlappyBird/PipeManager.h"

#include "GameObjects/Character/Siva.h"
#include "GameObjects/Character/Cat.h"

//Scene Header;
#include "Scenes/Scene.h"
#include "System/GameManager.h"

extern Vector2 mousePos;
extern HINSTANCE hInst;
extern HWND hWnd;