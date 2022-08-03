// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#define CENTER_X (WIN_WIDTH*0.5f)
#define CENTER_Y (WIN_HEIGHT*0.5f)

#include <windows.h>
#include <string>
#include <vector>

using namespace std;

// Framework Header
#include "Utilities/Singleton.h"
#include "Utilities/GameMath.h"

using namespace GameMath;

// GameObject Header
#include "GameObject/Object.h"
#include "GameObject/Circle.h"
#include "GameObject/Rect.h"
#include "GameObject/ObjectManager.h"



// Scene Header
#include "Scene/Scene.h"
#include "System/GameManager.h"

extern POINT mousePos;