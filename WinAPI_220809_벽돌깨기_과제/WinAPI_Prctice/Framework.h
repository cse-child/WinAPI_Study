#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN      

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define CENTER_X (WIN_WIDTH * 0.5f)
#define CENTER_Y (WIN_HEIGHT * 0.5f)

#define PI 3.1415f

#define RED RGB(255,0,0)
#define GREEN RGB(0,255,0)
#define BLUE RGB(0,0,255)
#define YELLOW RGB(255,255,0)
#define CYAN RGB(0,255,255)
#define MAGENTA RGB(255,0,255)
#define BLACK RGB(0,0,0)
#define WHITE RGB(255,255,255)
#define GRAY RGB(100,100,100)

#define KEY_DOWN(k) Keyboard::Get()->Down(k)
#define KEY_UP(k) Keyboard::Get()->Up(k)
#define KEY_PRESS(k) Keyboard::Get()->Press(k)

#include <windows.h>
#include <string>
#include <vector>

using namespace std;

// 폴더를 만들면 C/C++ -> 일반 -> 추가디렉터리 "./" 추가

// Framework Header;
#include "Utilities/Singletone.h"
#include "Utilities/Keyboard.h"

#include "Math/Vector2.h"
#include "Math/GameMath.h"

using namespace GameMath;

// GameObject Header
#include "GameObject/Basic/Circle.h"
#include "GameObject/Basic/Line.h"
#include "GameObject/Basic/Rect.h"

#include "GameObject/Shooting/Bullet.h"

#include "GameObject/BrickBreaker/BrickBreaker.h"


// Scene Header;
#include "Scenes/Scene.h"
#include "System/GameManager.h"

extern Vector2 mousePos; // 전역변수 선언