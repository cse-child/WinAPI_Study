#pragma once

class Timer : public Singleton<Timer>
{
public:
	Timer();
	~Timer();

	void Update();
	void Render(HDC hdc);

	float GetTimeElapsed() { return timeElapsed; }

private:
	float timeScale = 0.0f;
	float timeElapsed = 0.0f;
	
	// __int64: 서버관련, 시간관련(CPU의 진동수로 시간계산)
	// CPU 진동수 단위가 매우커서 32비트로는 계산 불가
	__int64 curTime = 0;
	__int64 lastTime = 0;
	__int64 periodFrequency = 0;

	int frameRate = 0;
	int frameCount = 0;

	float oneSecCount = 0.0f;
};