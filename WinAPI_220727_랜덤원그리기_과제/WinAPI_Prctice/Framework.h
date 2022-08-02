#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN      

#include <windows.h>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

// 폴더를 만들면 C/C++ -> 일반 -> 추가디렉터리 "./" 추가

// Framework Header;
#include "Utilities/Singletone.h"


// GameObject Header
#include "GameObject/Circle.h"


// Scene Header;
#include "Scenes/Scene.h"
#include "Manager/GameManager.h"

extern POINT mousePos; // 전역변수 선언