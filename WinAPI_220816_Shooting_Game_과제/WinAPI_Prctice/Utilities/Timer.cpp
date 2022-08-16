#include "Framework.h"

Timer::Timer()
{
	// 1�ʵ��� CPU �������� ��ȯ�ϴ� �Լ�
	QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency);

	// ���� CPU �������� ��ȯ�ϴ� �Լ�
	QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);

	timeScale = 1.0f / (float)periodFrequency; // ����


}

Timer::~Timer()
{
}

void Timer::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&curTime);
	// ������ ���� ���ϱ�
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
