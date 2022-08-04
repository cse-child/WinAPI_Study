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

#include "Math/Vector2.h"
#include "Math/GameMath.h"

using namespace GameMath;

// GameObject Header
#include "GameObject/Circle.h"
#include "GameObject/Bullet.h"
#include "GameObject/BulletManager.h" // Plane이 써야하고, manager에서 bullet을 써야하니까 이 위치가 적당
#include "GameObject/Plane.h"


// Scene Header;
#include "Scenes/Scene.h"
#include "System/GameManager.h"

extern Vector2 mousePos; // 전역변수 선언