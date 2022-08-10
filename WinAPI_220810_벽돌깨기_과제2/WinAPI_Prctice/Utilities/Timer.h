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
	
	// __int64: ��������, �ð�����(CPU�� �������� �ð����)
	// CPU ������ ������ �ſ�Ŀ�� 32��Ʈ�δ� ��� �Ұ�
	__int64 curTime = 0;
	__int64 lastTime = 0;
	__int64 periodFrequency = 0;

	int frameRate = 0;
	int frameCount = 0;

	float oneSecCount = 0.0f;
};