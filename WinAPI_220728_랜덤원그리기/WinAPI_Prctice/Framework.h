#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN      

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define CENTER_X (WIN_WIDTH * 0.5f)
#define CENTER_Y (WIN_HEIGHT * 0.5f)

#include <windows.h>
#include <string>
#include <vector>

using namespace std;

// 폴더를 만들면 C/C++ -> 일반 -> 추가디렉터리 "./" 추가

// Framework Header;
#include "Utilities/Singletone.h"
#include "Utilities/GameMath.h"

using namespace GameMath;

// GameObject Header
#include "GameObject/Circle.h"
#include "GameObject/SpawnCircle.h"


// Scene Header;
#include "Scenes/Scene.h"
#include "Manager/GameManager.h"

extern POINT mousePos; // 전역변수 선언