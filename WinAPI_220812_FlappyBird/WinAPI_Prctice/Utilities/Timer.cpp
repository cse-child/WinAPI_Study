#include "Framework.h"

Timer::Timer()
{
	// 1초동안 CPU 진동수를 반환하는 함수
	QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency);

	// 현재 CPU 진동수를 반환하는 함수
	QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);

	timeScale = 1.0f / (float)periodFrequency; // 역수


}

Timer::~Timer()
{
}

void Timer::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&curTime);
	// 프레임 간격 구하기
	timeElapsed = (float)(curTime - lastTime) * timeScale;

	//if (lockFPS < abs(lockFPS - 0.001f))
	if(lockFPS != 0.0f)
	{
		while (timeElapsed < (1.0f / lockFPS))
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&curTime);
			timeElapsed = (float)(curTime - lastTime) * timeScale;
		}
	}

	lastTime = curTime;

	frameCount++;
	oneSecCount += timeElapsed;

	if (oneSecCount >= 1.0f)
	{
		frameRate = frameCount;
		frameCount = 0;
		oneSecCount = 0.0f;
	}
}

void Timer::Render(HDC hdc)
{
	wstring str;
	str = L"FPS : " + to_wstring(frameRate);
	TextOut(hdc, 0, 0, str.c_str(), str.length());
	str = L"Elapse : " + to_wstring(timeElapsed);
	TextOut(hdc, 0, 20, str.c_str(), str.length());
}
